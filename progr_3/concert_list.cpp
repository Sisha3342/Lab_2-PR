#include "concert_list.h"

void concert::get_info(std::string info)
{
	std::vector<std::string> results;
	boost::split(results, info, [](char c) {return c == ' ' || c == ';' || c == ':' || c == '-'; });

	name = results[0];
	capacity = std::stol(results[1]);
	tickets_left = std::stol(results[2]);
	date.tm_year = std::stol(results[4]);
	date.tm_mon = std::stol(results[5]);
	date.tm_mday = std::stol(results[6]);
	date.tm_hour = std::stol(results[7]);
	date.tm_min = std::stol(results[8]);
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
	out << conc.name << ";" << conc.capacity << ";" << conc.tickets_left << "; " << conc.date.tm_year << "-" << conc.date.tm_mon << "-" << conc.date.tm_mday << " " << conc.date.tm_hour << ":" << conc.date.tm_min;
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
	concert conc{}; std::string temp;

	std::getline(in, temp);
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
	list[concerts_count].name = conc.name;

	concerts_count++;
}

int concert_list::get_concerts_count() const
{
	return concerts_count;
}

concert& concert_list::operator[](int index) const
{
	if (index >= concerts_count || index < 0)
		throw std::out_of_range("Invalid index. Out of list range");

	return list[index];
}

int compare_name(concert const& concert1, concert const& concert2)
{
	const std::string name1 = concert1.name;
	const std::string name2 = concert2.name;

	return name1 < name2;
}

//int compare_date(const void* concert1, const void* concert2)
//{
//	tm date1 = ((concert*)concert1)->date;
//	tm date2 = ((concert*)concert2)->date;
//
//	if (date1.tm_year != date2.tm_year)
//		return date2.tm_year - date1.tm_year;
//
//	if (date1.tm_mon != date2.tm_mon)
//		return date2.tm_mon - date1.tm_mon;
//
//	if (date1.tm_mday != date2.tm_mday)
//		return date2.tm_mday - date1.tm_mday;
//
//	return 0;
//}

void concert_list::sort_by_name() const
{
	std::sort(list, list + concerts_count, compare_name);
}

//void concert_list::sort_by_date() const
//{
//	qsort(list, concerts_count, sizeof(concert), compare_date);
//}