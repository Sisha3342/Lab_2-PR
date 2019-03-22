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

std::vector<concert>::iterator concert_list::begin()
{
	return list_.begin();
}

std::vector<concert>::iterator concert_list::end()
{
	return list_.end();
}

std::ostream& operator<< (std::ostream& out, concert_list const& list1)
{
	for(auto element: list1.list_)
	{
		out << element << std::endl;
	}

	return out;
}

std::istream& operator>> (std::istream& in, concert_list& list1)
{
	concert conc{}; std::string temp;

	std::getline(in, temp);
	conc.get_info(temp);

	list1.list_.push_back(conc);

	return in;
}

void concert_list::reserve_ticket(int conc_index)
{
	list_[conc_index].reserve();
}

int concert_list::get_concerts_count() const
{
	return list_.size();
}

concert& concert_list::operator[](const int index)
{
	if (index >= list_.size() || index < 0)
		throw std::out_of_range("Invalid index. Out of list range");

	return list_[index];
}

void concert_list::sort_by_name()
{
	std::sort(list_.begin(), list_.end(), [](concert const& c1, concert const& c2) -> bool
	{
		return c1.name < c2.name;
	});
}

void concert_list::sort_by_date()
{
	std::sort(list_.begin(), list_.end(), [](concert c1, concert c2) -> bool
	{
		return mktime(&c1.date) < mktime(&c2.date);
	});
}

std::vector<concert>::iterator concert_list::find_first_name(std::string const& c_name)
{
	return std::find_if(list_.begin(), list_.end(), [&c_name](concert const& c)
	{
		return c.name == c_name;
	});
}

std::vector<concert>::iterator concert_list::find_first_date_between(tm const& date1, tm const& date2)
{
	tm d1 = date1, d2 = date2;

	return std::find_if(list_.begin(), list_.end(), [&d1, &d2](concert & c)
	{
		return (mktime(&d1) <= mktime(&c.date)) && (mktime(&c.date) <= mktime(&d2));
	});
}