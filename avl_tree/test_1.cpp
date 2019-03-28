#include "AVL_tree.h"

int main()
{
	avl_tree root;

	root.insert(10);
	root.insert(12);
	root.insert(9);
	root.insert(13);

	std::cout << root.get_height();

	return 0;
}