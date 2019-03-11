#include "concert_list.h"

std::ostream& operator<< (std::ostream& out, concert_list const& list1)
{
	for (int i = 0; i < list1.concerts_count; i++)
		out << list1.list[i].name << " " << list1.list[i].tickets_left << " " << list1.list[i].capacity << " " << list1.list[i].date << std::endl;

	return out;
}