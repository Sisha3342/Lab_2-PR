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
		temp->key = key;
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
		temp->balance_factor = 0;

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
	node* temp = current_node;

	while(temp != nullptr)
	{
		temp->height = std::max(height_with_param(temp->left_), height_with_param((temp->right_))) + 1;

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

		//rotate part end

		temp = temp->parent;
	}

	while (root->parent)
	{
		root = root->parent;
	}
 }

node* avl_tree::single_right_rotate(node*& change_node)
{
	node* temp = change_node->left_;
	change_node->left_ = temp->right_;
	temp->right_ = change_node;

	temp->parent = change_node->parent;
	change_node->parent = temp;

	if (temp->parent)
	{
		if (temp->parent->left_ == change_node)
			temp->parent->left_ = temp;
		else
			temp->parent->right_ = temp;
	}

	recount_height(temp->right_);

	temp->right_->balance_factor = height_with_param(temp->right_->left_) - height_with_param(temp->right_->right_);
	temp->balance_factor = height_with_param(temp->right_) - height_with_param(temp->left_);

	return temp;
}

node* avl_tree::single_left_rotate(node*& change_node)
{
	node* temp = change_node->right_;
	change_node->right_ = temp->left_;
	temp->left_ = change_node;

	temp->parent = change_node->parent;
	change_node->parent = temp;

	if (temp->parent)
	{
		if (temp->parent->left_ == change_node)
			temp->parent->left_ = temp;
		else
			temp->parent->right_ = temp;
	}

	recount_height(temp->left_);

	temp->left_->balance_factor = height_with_param(temp->left_->right_) - height_with_param(temp->left_->left_);
	temp->balance_factor = height_with_param(temp->right_) - height_with_param(temp->left_);

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