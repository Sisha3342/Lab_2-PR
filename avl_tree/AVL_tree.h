#pragma once
#include <iostream>

class avl_tree
{
	int key;
	avl_tree* left_;
	avl_tree* right_;
	int height;
	avl_tree* parent;

	void recount_height(avl_tree* t);

public:

	avl_tree();

	void insert(int key);
	int get_height() const;
};