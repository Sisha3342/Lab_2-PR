#include "rail_list.h"

railway::railway(std::string info)
{
	std::string date_format = "%Y-%m-%d %H:%M";
	std::string temp_str = info;

	std::vector<std::string> temp;
	int pos2 = 0;

	while (pos2 != -1)
	{
		pos2 = temp_str.find(';');
		temp.push_back(temp_str.substr(0, pos2));
		temp_str = temp_str.substr(pos2 + 1);
	}

	start_city = temp[0];
	end_city = temp[2];
	capacity = std::stol(temp[4]);
	tickets_left = std::stol(temp[5]);

	std::stringstream oss(temp[1]);
	oss >> std::get_time(&start_date, date_format.c_str());
	oss.clear();
	oss.str(std::string());
	oss << temp[3];
	oss >> std::get_time(&end_date, date_format.c_str());
}

std::string correct_date(tm to_convert_date)
{
	std::string date = std::to_string(to_convert_date.tm_year + 1900) + "-";

	if (to_convert_date.tm_mon + 1 <= 9)
		date += "0";
	date += std::to_string(to_convert_date.tm_mon + 1) + "-";

	if (to_convert_date.tm_mday <= 9)
		date += "0";
	date += std::to_string(to_convert_date.tm_mday);

	return date;
}

std::string correct_time(tm to_convert_date)
{
	std::string time_;

	if (to_convert_date.tm_hour <= 9)
		time_ += "0";
	time_ += std::to_string(to_convert_date.tm_hour) + ":";

	if (to_convert_date.tm_min <= 9)
		time_ += "0";
	time_ += std::to_string(to_convert_date.tm_min);

	return time_;
}


std::ostream& operator<< (std::ostream& out, railway const& rail)
{
	out << rail.take_full_string_info();

	return out;
}

bool railway::reserve_ticket()
{
	if (tickets_left == 0)
	{
		return false;
	}
	else
	{
		tickets_left--;

		return true;
	}
}

std::string railway::take_full_string_info() const
{
	return start_city + ";" + correct_date(start_date) + " " + correct_time(start_date) + ";" + 
		end_city + ";" + correct_date(end_date) + " " + correct_time(end_date) + ";" +
		std::to_string(capacity) + ";" + std::to_string(tickets_left);
}

std::istream& operator>> (std::istream& in, railways_list& list1)
{
	std::string temp;

	std::getline(in, temp);

	if (!temp.empty())
	{
		list1.list_.push_back(railway(temp));
	}

	return in;
}

railway& railways_list::operator[](size_t index)
{
	if (index >= list_.size() || index < 0)
		throw std::out_of_range("Invalid index. Out of list range");

	return list_[index];
}

std::ostream& operator<<(std::ostream& out, railways_list const& list1)
{
	for (size_t i = 0; i < list1.list_.size(); i++)
	{
		out << list1.list_[i] << std::endl;
	}

	return out;
}

void railways_list::sort_by_start_date()
{
	std::sort(list_.begin(), list_.end(), [](railway r1, railway r2) -> bool
	{
		return mktime(&r1.start_date) < mktime(&r2.start_date);
	});
}

void railways_list::add_railway(railway const& r)
{
	list_.push_back(r);
}

int railways_list::get_railways_count()
{
	return list_.size();
}

railways_list& railways_list::operator=(railways_list const& rlist)
{
	if (this == &rlist)
		return *this;

	list_ = rlist.list_;

	return *this;
}