#include "AVL_tree.h"
#include <algorithm>

avl_tree::avl_tree()
{
	key = 0;
	left_ = right_ = parent = nullptr;
	height = 1;
}

avl_tree::~avl_tree()
{
	while (right_ != nullptr || left_ != nullptr)
	{
		avl_tree* temp = this;

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
}

int avl_tree::get_height() const
{
	return height;
}

void avl_tree::insert(int key)
{
	avl_tree* temp = this, *prev = this;
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

		temp = new avl_tree;
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

void avl_tree::recount_height(avl_tree* current_node)
{
	avl_tree* temp = current_node->parent;

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

void avl_tree::rebalance_tree(avl_tree* &current_node)
{
	int height_left = 1, height_right = 1;

	if (current_node->left_ != nullptr)
	{
		height_left = current_node->left_->get_height();
	}
	if (current_node->right_ != nullptr)
	{
		height_right = current_node->right_->get_height();
	}

	const int height_difference = height_left - height_right;

	if (height_difference == 2)
	{
		
	}
	else if (height_difference == -2)
	{
		
	}
}
