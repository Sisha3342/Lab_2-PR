#include "AVL_tree.h"

avl_tree::avl_tree()
{
	key_ = height_ = 0;
	left_ = nullptr;
	right_ = nullptr;
}


int avl_tree::get_tree_height() const
{
	return height_;
}

void avl_tree::set_height()
{
	if (left_->key_ != right_->key_)
	{
		if (left_->height_ > right_->height_)
			height_ = left_->height_ + 1;
		else if (left_->height_ <= right_->height_)
			height_ = right_->height_ + 1;
	}
}


void avl_tree::add_node(double key)
{
	if (right_ == nullptr && left_ == nullptr)
	{
		key_ = key;
		std::unique_ptr<avl_tree> temp(new avl_tree);
		std::unique_ptr<avl_tree> temp1(new avl_tree);
		right_ = std::move(temp);
		left_ = std::move(temp1);
	}
		

	if (key > key_)
	{
		right_->add_node(key);
	}
	else if (key < key_)
	{
		left_->add_node(key);
	}

	set_height();
}