#pragma once
#include <iostream>

class avl_tree
{
	int key;
	avl_tree* left_;
	avl_tree* right_;
	int height;
	avl_tree* parent;

	void recount_height(avl_tree* current_node);
	void rebalance_tree(avl_tree* &current_node);

public:

	avl_tree();

	void insert(int key);
	int get_height() const;

	~avl_tree();
};