#include "concert_list.h"

void concert::get_info(char* info)
{
	char *div, *div1;

	strcpy_s(name, strtok_s(info, ";", &div));
	capacity = strtol(strtok_s(0, ";", &div), &div1, 10);
	tickets_left = strtol(strtok_s(0, ";", &div), &div1, 10);
	date.tm_year = strtol(strtok_s(0, ".", &div), &div1, 10);
	date.tm_mon = strtol(strtok_s(0, ".", &div), &div1, 10);
	date.tm_mday = strtol(strtok_s(0, " ", &div), &div1, 10);
	date.tm_hour = strtol(strtok_s(0, ":", &div), &div1, 10);
	date.tm_min = strtol(strtok_s(0, ":", &div), &div1, 10);
}

void concert::reserve()
{
	if (tickets_left == 0)
	{
		throw std::length_error("There are no tickets left for this concert");
	}
	else
	{
		tickets_left--;
	}
}

std::ostream& operator<< (std::ostream& out, concert const& conc)
{
	out << conc.name << ";" << conc.capacity << ";" << conc.tickets_left << "; " << conc.date.tm_year << "." << conc.date.tm_mon << "." << conc.date.tm_mday << " " << conc.date.tm_hour << ":" << conc.date.tm_min;
	return out;
}

std::ostream& operator<< (std::ostream& out, concert_list const& list1)
{
	for (int i = 0; i < list1.concerts_count; i++)
		out << list1.list[i] << std::endl;

	return out;
}

std::istream& operator>> (std::istream& in, concert_list& list1)
{
	concert conc{}; char temp[MAX_LENGTH];

	in.getline(temp, MAX_LENGTH);

	conc.get_info(temp);

	list1.append(conc);

	return in;
}

void concert_list::reserve_ticket(int conc_index)
{
	list[conc_index].reserve();
}

void concert_list::append(concert const& conc)
{
	if (concerts_count == MAX_SIZE)
		throw std::length_error("Too many concerts in the list");

	list[concerts_count].tickets_left = conc.tickets_left;
	list[concerts_count].capacity = conc.capacity;
	list[concerts_count].date = conc.date;
	strcpy_s(list[concerts_count].name, MAX_LENGTH, conc.name);

	concerts_count++;
}

int concert_list::get_concerts_count()
{
	return concerts_count;
}

concert& concert_list::operator[](int index)
{
	if (index >= concerts_count || index < 0)
		throw std::out_of_range("Invalid index. Out of list range");

	return list[index];
}

int compare_name(const void* concert1, const void* concert2)
{
	return strcmp(((concert*)concert1)->name, ((concert*)concert2)->name);
}

int compare_date(const void* concert1, const void* concert2)
{
	tm date1 = ((concert*)concert1)->date;
	tm date2 = ((concert*)concert2)->date;

	if (date1.tm_year != date2.tm_year)
		return date2.tm_year - date1.tm_year;

	if (date1.tm_mon != date2.tm_mon)
		return date2.tm_mon - date1.tm_mon;

	if (date1.tm_mday != date2.tm_mday)
		return date2.tm_mday - date1.tm_mday;

	return 0;
}

void concert_list::sort_by_name()
{
	qsort(list, concerts_count, sizeof(concert), compare_name);
}

void concert_list::sort_by_date()
{
	qsort(list, concerts_count, sizeof(concert), compare_date);
}