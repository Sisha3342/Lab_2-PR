#include "concert_list.h"

void DisplayMenu(concert_list list1);

int main()
{
	setlocale(LC_ALL, "rus");
	int choice = 0;
	concert_list list_1("list.txt");


	while(choice != 6)
	{
		DisplayMenu(list_1);
		choice = _getch() - 48;
		system("cls");

		switch (choice)
		{
		case 1:
			std::cout << list_1;
			std::cout << std::endl << "Press any key to go back to menu";
			_getch();
			break;
		case 2:
			std::cin >> list_1;
			break;
		case 3:
			int index;
			std::cout << list_1;
			std::cout << std::endl << "Input the index of the concert you want to reserve ticket for: ";
			std::cin >> index;

			if (index > list_1.get_concerts_count() || index <= 0)
				throw "Invalid index choice. Out of list range";
			else
				list_1.reserve_ticket(index - 1);

			break;
		case 4:
			list_1.sort_for_date();
			break;
		case 5:
			list_1.sort_for_name();
			break;
		case 6:
			break;
		default:
			std::cout << "There is no such point of menu. Please, choose another one. Press any key to go back to menu";
			_getch();
			break;
		}

		system("cls");
	}

	list_1.place_in_the_file("list.txt");

	return 0;
}

void DisplayMenu(concert_list list1)
{
	std::cout << "List was created from the list.txt file (already " << list1.get_concerts_count() << " in the list)" << std::endl;
	std::cout << "1) Display the list" << std::endl;
	std::cout << "2) Add a concert to the list" << std::endl;
	std::cout << "3) Reserve a ticket" << std::endl;
	std::cout << "4) Sort the list according to the date" << std::endl;
	std::cout << "5) Sort the list according to the name" << std::endl;
	std::cout << "6) Exit" << std::endl;
}
