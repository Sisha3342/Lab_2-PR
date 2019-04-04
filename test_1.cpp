#include "AVL_tree.h"

using namespace avlTree;

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

	for (avl_tree::left_iterator it = my_tree.lbegin(); it != my_tree.lend(); it++)
		std::cout << *(it);

	std::cout << "\n";

	for (avl_tree::right_iterator it = my_tree.rbegin(); it != my_tree.rend(); it++)
		std::cout << *(it);

	std::cout << "\n";

	for (avl_tree::deep_iterator it = my_tree.dbegin(); it != my_tree.dend(); it++)
		std::cout << *(it);



	//std::cout << my_tree.get_height();

	return 0;
}