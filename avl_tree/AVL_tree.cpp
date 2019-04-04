#include "AVL_tree.h"

avl_tree::avl_tree()
{
	root = new node;
	root->key = root->balance_factor = 0;
	root->left_ = root->right_ = root->parent = nullptr;
	root->height = 1;
}

avl_tree::avl_tree(int value)
{
	root = new node;
	root->balance_factor = 0;
	root->key = value;
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

void avl_tree::remove_node(int value)
{
	node* temp = root;

	while(temp)
	{
		if (value > temp->key)
			temp = temp->right_;
		else if (value < temp->key)
			temp = temp->left_;
		else
			break;
	}

	if (temp)
	{
		if (temp->left_ == nullptr && temp->right_ == nullptr)
		{
			node* deleted_parent = temp->parent;

			if (deleted_parent->left_ == temp)
				deleted_parent->left_ = nullptr;
			else
				deleted_parent->right_ = nullptr;

			recount_height(deleted_parent);
			rebalance_tree(deleted_parent);

			delete temp;
		}
		else
		{
			node* replacement;
			node* rep_parent, *rep_side;

			if (height_with_param(temp->right_) < height_with_param(temp->left_))
			{
				replacement = find_max(temp->left_);
				temp->key = replacement->key;
				rep_parent = replacement->parent;
				rep_side = replacement->left_;
				delete replacement;
				if (rep_parent)
					rep_parent->right_ = rep_side;
				if (rep_side)
					rep_side->parent = rep_parent;
			}
			else
			{
				replacement = find_min(temp->right_);
				temp->key = replacement->key;
				rep_parent = replacement->parent;
				rep_side = replacement->right_;
				delete replacement;

				if (rep_parent)
					rep_parent->left_ = rep_side;
				if (rep_side)
					rep_side->parent = rep_parent;
			}

			recount_height(rep_parent);
			rebalance_tree(rep_parent);
		}
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

node* avl_tree::find_max(node* current_node) const
{
	node* temp = current_node;

	while(temp->right_ != nullptr)
	{
		temp = temp->right_;
	}

	return temp;
}

node* avl_tree::find_min(node* current_node) const
{
	node* temp = current_node;

	while (temp->left_ != nullptr)
	{
		temp = temp->left_;
	}

	return temp;
}

int avl_tree::right_height() const
{
	node* temp = root;
	int height = 0;

	while (temp)
	{
		temp = temp->right_;
		height++;
	}

	return height;
}

int avl_tree::left_height() const
{
	node* temp = root;
	int height = 0;

	while (temp)
	{
		temp = temp->left_;
		height++;
	}

	return height;
}

int avl_tree::right_iterator::deeper_right(int count) const
{
	node* temp = tree_.root;

	while (count--)
		temp = temp->right_;

	return temp->key;
}

int avl_tree::left_iterator::deeper_left(int count) const
{
	node* temp = tree_.root;

	while (count--)
		temp = temp->left_;

	return temp->key;
}

int avl_tree::deep_iterator::in_deep(int count) const
{
	node* temp = tree_.root;

	while(count--)
	{
		if (height_with_param(temp->left_) > height_with_param(temp->right_))
			temp = temp->left_;
		else
			temp = temp->right_;
	}

	return temp->key;
}


avl_tree::right_iterator::right_iterator(avl_tree const& itr_tree) : tree_(itr_tree), index_(0)
{
}

avl_tree::right_iterator::right_iterator(avl_tree const& itr_tree, bool) : tree_(itr_tree), index_(itr_tree.right_height())
{
}


avl_tree::right_iterator avl_tree::right_iterator::operator++(int)
{
	index_++;

	return *this;
}

int avl_tree::right_iterator::operator*() const
{
	return deeper_right(index_);
}

avl_tree::right_iterator avl_tree::rbegin()
{
	return right_iterator(*this);
}

avl_tree::right_iterator avl_tree::rend() const
{
	return right_iterator(*this, true);
}

bool avl_tree::right_iterator::operator!=(right_iterator const& iter) const
{
	return index_ != iter.index_;
}

bool avl_tree::right_iterator::operator==(right_iterator const& iter) const
{
	return index_ == iter.index_;
}

avl_tree::left_iterator::left_iterator(avl_tree const& itr_tree) : tree_(itr_tree), index_(0)
{
}

avl_tree::left_iterator::left_iterator(avl_tree const& itr_tree, bool) : tree_(itr_tree), index_(itr_tree.right_height())
{
}


avl_tree::left_iterator avl_tree::left_iterator::operator++(int)
{
	index_++;

	return *this;
}

int avl_tree::left_iterator::operator*() const
{
	return deeper_left(index_);
}

avl_tree::left_iterator avl_tree::lbegin()
{
	return left_iterator(*this);
}

avl_tree::left_iterator avl_tree::lend() const
{
	return left_iterator(*this, true);
}

bool avl_tree::left_iterator::operator!=(left_iterator const& iter) const
{
	return index_ != iter.index_;
}

bool avl_tree::left_iterator::operator==(left_iterator const& iter) const
{
	return index_ == iter.index_;
}

avl_tree::deep_iterator::deep_iterator(avl_tree const& itr_tree) : tree_(itr_tree), index_(0)
{
}

avl_tree::deep_iterator::deep_iterator(avl_tree const& itr_tree, bool) : tree_(itr_tree), index_(itr_tree.get_height())
{
}


avl_tree::deep_iterator avl_tree::deep_iterator::operator++(int)
{
	index_++;

	return *this;
}

int avl_tree::deep_iterator::operator*() const
{
	return in_deep(index_);
}

avl_tree::deep_iterator avl_tree::dbegin() const
{
	return deep_iterator(*this);
}

avl_tree::deep_iterator avl_tree::dend() const
{
	return deep_iterator(*this, true);
}

bool avl_tree::deep_iterator::operator!=(deep_iterator const& iter) const
{
	return index_ != iter.index_;
}

bool avl_tree::deep_iterator::operator==(deep_iterator const& iter) const
{
	return index_ == iter.index_;
}