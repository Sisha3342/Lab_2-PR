#include "AVL_tree.h"

int main()
{
	avl_tree root;

	root.add_node(10);
	root.add_node(12);
	root.add_node(11);

	std::cout << root.right_->get_tree_height();//root.get_tree_height();

	return 0;
}