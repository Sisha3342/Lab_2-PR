#include "concert_list.h"

std::ostream& operator<< (std::ostream& out, concert_list const& list1)
{
	for (int i = 0; i < list1.concerts_count; i++)
		out << list1.list[i].name << ";" << list1.list[i].tickets_left << ";" << list1.list[i].capacity << ";" << list1.list[i].date << std::endl;

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

void concert_list::reserve_ticket(int conc_index)
{
	list[conc_index].reserve();
}

void concert_list::append(concert const& conc)
{
	if (concerts_count == MAX_SIZE)
		throw "Too many concerts in the list!";

	concerts_count++;

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
	if (index >= concerts_count || index < 0)
		throw "Incorrect index choice. Out of list range.";

	return list[index];
}

int compare_name(const void* concert1, const void* concert2)
{
	return strcmp(((concert*)concert1)->name, ((concert*)concert2)->name);
}

int compare_date(const void* concert1, const void* concert2)
{
	return strcmp(((concert*)concert1)->date, ((concert*)concert2)->date);
}

void concert_list::sort_for_name()
{
	qsort(list, concerts_count, sizeof(concert), compare_name);
}

void concert_list::sort_for_date()
{
	qsort(list, concerts_count, sizeof(concert), compare_date);
}


void concert_list::place_in_the_file(const char* file_path)
{
	std::ofstream of1(file_path);

	if(!of1.is_open())
	{
		throw "Error! Can't open the file";
	}

	for (int i = 0; i < concerts_count; i++)
	{
		of1 << list[i].name << "; " << list[i].tickets_left << "; " << list[i].capacity << "; " << list[i].date << std::endl;
	}

	of1.close();
}