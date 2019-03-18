#include "concert_list.h"

void concert::get_info(std::string info)
{
	std::string format = "%Y-%m-%d %H:%M";
	std::vector<std::string> results;
	boost::split(results, info, [](char c) {return  c == ';' || c == '\n'; });

	name = results[0];
	capacity = std::stol(results[1]);
	tickets_left = std::stol(results[2]);
	std::stringstream ss(results[3]);
	ss >> std::get_time(&date, format.c_str());
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

	out << conc.name << ";" << conc.capacity << ";" << conc.tickets_left << "; " << conc.date.tm_year + 1900 << "-" << conc.date.tm_mon + 1 << "-" << conc.date.tm_mday << " " << conc.date.tm_hour << ":" << conc.date.tm_min;

	return out;
}

std::ostream& operator<< (std::ostream& out, concert_list const& list1)
{
	for (auto i = 0; i < list1.concerts_count; i++)
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

concert& concert_list::operator[](const int index) const
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

int compare_date(concert const& concert1, concert const& concert2)
{ 
	tm date1 = concert1.date;
	tm date2 = concert2.date;

	return mktime(&date2) < mktime(&date1);
}

void concert_list::sort_by_name() const
{
	std::sort(list, list + concerts_count, compare_name);
}

void concert_list::sort_by_date() const
{
	std::sort(list, list + concerts_count, compare_date);
}