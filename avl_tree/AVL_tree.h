#pragma once
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
public:
	node* root;

	void recount_height(node* current_node);
	void rebalance_tree(node* &current_node);

	node* single_right_rotate(node* &change_node);
	node* single_left_rotate(node* &change_node);
	node* double_right_rotate(node* &change_node);
	node* double_left_rotate(node* &change_node);

	avl_tree();

	void insert(int key);
	int get_height() const;

	~avl_tree();

	friend int height_with_param(node* tree);
};