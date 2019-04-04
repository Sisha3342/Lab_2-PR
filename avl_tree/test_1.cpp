#include "AVL_tree.h"

int main()
{
	avl_tree my_tree;

	my_tree.insert(40);
	my_tree.insert(20);
	my_tree.insert(55);
	my_tree.insert(10);
	my_tree.insert(30);
	my_tree.insert(50);
	my_tree.insert(27);
	my_tree.insert(70);
	my_tree.insert(61);

	my_tree.remove_node(55);

	std::cout << my_tree.get_height();

	return 0;
}