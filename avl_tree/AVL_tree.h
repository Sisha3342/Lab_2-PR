#pragma once
#include <iostream>

class avl_tree
{
public:
	double key_;
	std::unique_ptr<avl_tree> right_;
	std::unique_ptr<avl_tree> left_;
	int height_;

	int balance_factor();
	void set_height();
public:
	avl_tree();

	void add_node(double key);
	int get_tree_height() const;

};