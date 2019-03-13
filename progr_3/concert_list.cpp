#include "concert_list.h"

std::ostream& operator<< (std::ostream& out, concert_list const& list1)
{
	for (int i = 0; i < list1.concerts_count; i++)
		out << list1.list[i].name << " " << list1.list[i].tickets_left << " " << list1.list[i].capacity << " " << list1.list[i].date << std::endl;

	return out;
}

std::istream& operator>> (std::istream& in, concert_list& list1)
{
	concert conc; char c = 'c';

	while(c == 'c')
	{
		std::cout << "Concert name: ";
		in.getline(conc.name, MAX_LENGTH);
		std::cout << "Tickets left: ";
		in >> conc.tickets_left;
		std::cout << "Capacity: ";
		in >> conc.capacity;
		std::cout << "Date and time(ex. 2019-04-06 19:00): ";
		in.ignore();
		in.getline(conc.date, MAX_LENGTH);

		list1.append(conc);

		std::cout << "Concert was added. Press 'q' to quit or 'c' to put another concert in the list: ";
		in >> c;
		in.ignore();
	}

	return in;
}

void concert_list::append(concert const& conc)
{
	list = (concert*)realloc(list, (++concerts_count) * sizeof(concert));

	list[concerts_count - 1].tickets_left = conc.tickets_left;

	list[concerts_count - 1].capacity = conc.capacity;
	strcpy_s(list[concerts_count - 1].date, MAX_LENGTH, conc.date);
	strcpy_s(list[concerts_count - 1].name, MAX_LENGTH, conc.name);
}

int concert_list::get_concerts_count()
{
	return concerts_count;
}

concert& concert_list::operator[](int index)
{
	if (index >= concerts_count)
		throw "Incorrect index choice. Out of list range.";

	return list[index];
}