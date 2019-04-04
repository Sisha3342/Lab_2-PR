#pragma once
#include <algorithm>
#include <iostream>

struct node
{
	int key;
	node* left_;
	node* right_;
	node* parent;
	int height;
	int balance_factor;
};

class avl_tree
{
	node* root;

	void recount_height(node* current_node);
	void rebalance_tree(node* &current_node);

	node* single_right_rotate(node* &change_node);
	node* single_left_rotate(node* &change_node);
	node* double_right_rotate(node* &change_node);
	node* double_left_rotate(node* &change_node);
	node* find_max(node* current_node) const;
	node* find_min(node* current_node) const;

	friend int height_with_param(node* tree);
public:

	avl_tree();
	avl_tree(int value);
	avl_tree(avl_tree const&) = delete;
	avl_tree(avl_tree &&) = delete;

	void insert(int key);
	void remove_node(int value);
	int get_height() const;
	int right_height() const;
	int left_height() const;

	~avl_tree();

	class right_iterator;

	class right_iterator
	{
		avl_tree const& tree_;
		int index_;
		int deeper_right(int count) const;

	public:
		right_iterator(avl_tree const& itr_tree);
		right_iterator(avl_tree const& itr_tree, bool);
		int operator*() const;
		right_iterator operator++(int);
		bool operator!=(right_iterator const& iter) const;
		bool operator==(right_iterator const& iter) const;
	};

	right_iterator rbegin();
	right_iterator rend() const;

	class left_iterator;

	class left_iterator
	{
		avl_tree const& tree_;
		int index_;
		int deeper_left(int count) const;

	public:
		left_iterator(avl_tree const& itr_tree);
		left_iterator(avl_tree const& itr_tree, bool);
		int operator*() const;
		left_iterator operator++(int);
		bool operator!=(left_iterator const& iter) const;
		bool operator==(left_iterator const& iter) const;
	};

	left_iterator lbegin();
	left_iterator lend() const;

	class deep_iterator;

	class deep_iterator
	{
		avl_tree const& tree_;
		int index_;
		int in_deep(int count) const;

	public:
		deep_iterator(avl_tree const& itr_tree);
		deep_iterator(avl_tree const& itr_tree, bool);
		int operator*() const;
		deep_iterator operator++(int);
		bool operator!=(deep_iterator const& iter) const;
		bool operator==(deep_iterator const& iter) const;
	};

	deep_iterator dbegin() const;
	deep_iterator dend() const;

};