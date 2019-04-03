#include "AVL_tree.h"
#include <algorithm>

avl_tree::avl_tree()
{
	root = new node;
	root->key = root->balance_factor = 0;
	root->left_ = root->right_ = root->parent = nullptr;
	root->height = 1;
}

avl_tree::~avl_tree()
{
	while (root->right_ != nullptr || root->left_ != nullptr)
	{
		node* temp = root;

		while (temp->right_ != nullptr || temp->left_ != nullptr)
		{
			if (temp->right_ != nullptr)
				temp = temp->right_;
			else
				temp = temp->left_;
		}

		if (temp->parent->right_ == temp)
			temp->parent->right_ = nullptr;
		else
			temp->parent->left_ = nullptr;

		delete temp;
	}
	delete root;
}

int avl_tree::get_height() const
{
	return root->height;
}

int height_with_param(node* tree)
{
	if (tree == nullptr)
	{
		return 0;
	}
	else
	{
		return tree->height;
	}
}

void avl_tree::insert(int key)
{
	node* temp = root, *prev = root;
	bool right_from_prev = false;

	if (temp->key == 0)
	{
		temp->key = key; // выделять память только здесь!!!
	}
	else
	{
		while (temp != nullptr && key != temp->key)
		{
			prev = temp;

			if (temp->key < key)
			{
				temp = temp->right_;
				right_from_prev = true;
			}
			else if (temp->key > key)
			{
				temp = temp->left_;
				right_from_prev = false;
			}
			else
			{
				return;
			}
		}

		temp = new node;
		temp->parent = prev;
		temp->key = key;
		temp->left_ = temp->right_ = nullptr;
		temp->height = 1;

		if (right_from_prev)
		{
			prev->right_ = temp;
		}
		else
		{
			prev->left_ = temp;
		}

		recount_height(temp);
		rebalance_tree(temp);
	}
}

void avl_tree::recount_height(node* current_node)
{
	node* temp = current_node->parent;

	while(temp != nullptr)
	{
		if (temp->right_ == nullptr)
		{
			temp->height = temp->left_->height + 1;
		}
		else if (temp->left_ == nullptr)
		{
			temp->height = temp->right_->height + 1;
		}
		else
		{
			temp->height = std::max(temp->right_->height, temp->left_->height) + 1;
		}

		temp = temp->parent;
	}
}

void avl_tree::rebalance_tree(node* &current_node)
{
	node* temp = current_node;

	temp = temp->parent;

	while(temp)
	{
		//rotate part
		temp->balance_factor = height_with_param(temp->right_) - height_with_param(temp->left_);

		if (temp->balance_factor == -2)
		{
			if (temp->left_->balance_factor < 0)
				temp = single_right_rotate(temp);
			else
				temp = double_right_rotate(temp);
		}
		else if (temp->balance_factor == 2)
		{
			if (temp->right_->balance_factor > 0)
				temp = single_left_rotate(temp);
			else
				temp = double_left_rotate(temp);
		}

		temp->height = std::max(height_with_param(temp->left_), height_with_param(temp->right_)) + 1;
		temp->balance_factor = height_with_param(temp->right_) - height_with_param(temp->left_);
		//rotate part end

		temp = temp->parent;
	}

	/*while (root->parent)
	{
		temp = root->parent;
		root->right_ = temp->right_;
		root->left_ = temp->left_;
		root->key = temp->key;
		root->height = temp->height;
		root->balance_factor = temp->balance_factor;
		root->parent = temp->parent;
	}*/
 }

node* avl_tree::single_right_rotate(node*& change_node)
{
	/*bool is_root = false;

	if (node->key == this->key)
		is_root = true;*/

	node* temp = change_node->left_;
	change_node->left_ = temp->right_;
	temp->right_ = change_node;

	if (change_node->parent)
	{
		if (change_node->parent->left_ == change_node)
			change_node->parent->left_ = temp;
		else
			change_node->parent->right_ = temp;
	}

	temp->parent = change_node->parent;
	change_node->parent = temp;

	change_node->height = std::max(height_with_param(change_node->right_), height_with_param(change_node->left_)) + 1;
	temp->height = std::max(height_with_param(temp->right_), height_with_param(temp->left_)) + 1;

	change_node->balance_factor = height_with_param(temp->left_) - height_with_param(temp->right_);

	return temp;
}

node* avl_tree::single_left_rotate(node*& change_node)
{
	node* temp = change_node->right_;
	change_node->right_ = temp->left_;
	temp->left_ = change_node;

	if (change_node->parent)
	{
		if (change_node->parent->left_ == change_node)
			change_node->parent->left_ = temp;
		else
			change_node->parent->right_ = temp;
	}

	temp->parent = change_node->parent;
	change_node->parent = temp;

	change_node->height = std::max(height_with_param(change_node->right_), height_with_param(change_node->left_)) + 1;
	temp->height = std::max(height_with_param(temp->right_), height_with_param(temp->left_)) + 1;

	change_node->balance_factor = height_with_param(temp->right_) - height_with_param(temp->left_);

	return temp;
}

node* avl_tree::double_right_rotate(node*& change_node)
{
	change_node->left_ = single_left_rotate(change_node->left_);
	return single_right_rotate(change_node);
}

node* avl_tree::double_left_rotate(node*& change_node)
{
	change_node->right_ = single_right_rotate(change_node->right_);
	return single_left_rotate(change_node);
}