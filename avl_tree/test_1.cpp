#include "AVL_tree.h"

int main()
{
	avl_tree my_tree;

	my_tree.insert(20);
	my_tree.insert(10);
	my_tree.insert(21);
	my_tree.insert(9);
	my_tree.insert(11);
	my_tree.insert(12);

	std::cout << my_tree.get_height();

	return 0;
}