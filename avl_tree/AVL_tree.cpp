#include "AVL_tree.h"
#include <algorithm>

avl_tree::avl_tree()
{
	key = 0;
	left_ = right_ = parent = nullptr;
	height = 0;
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
		temp->height = 0;

		if (right_from_prev)
		{
			prev->right_ = temp;
		}
		else
		{
			prev->left_ = temp;
		}

		recount_height(temp);
	}
}

void avl_tree::recount_height(avl_tree* t)
{
	avl_tree* temp = t->parent;

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