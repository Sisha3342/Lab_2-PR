#include "railway_list.h"

void railway::get_info(std::string info)
{
	std::string date_format = "%Y-%m-%d %H:%M";
	std::string temp_str = info;

	std::vector<std::string> temp;
	int pos1 = 0, pos2 = 0;

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
	oss.flush();
	oss << temp[3];
	oss >> std::get_time(&end_date, date_format.c_str());
}

std::ostream& operator<< (std::ostream& out, railway const& rail)
{
	railway temp = rail;

	out << temp.take_full_string_info();

	return out;
}

std::istream& operator>> (std::istream& in, railways_list& list1)
{
	std::string temp;

	std::getline(in, temp);

	if (temp != "")
	{
		railway rail{};
		rail.get_info(temp);

		list1.list_.push_back(rail);
		list1.railways_count++;
	}

	return in;
}

railway& railways_list::operator[](int index)
{
	if (index >= list_.size() || index < 0)
		throw std::out_of_range("Invalid index. Out of list range");

	return list_[index];
}

std::ostream& operator<<(std::ostream& out, railways_list const& list1)
{
	for (int i = 0; i < list1.railways_count; i++)
		out << list1.list_[i];
	
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

std::string railway::take_full_string_info()
{
	std::string info = start_city + ";";

	info += std::to_string(start_date.tm_year + 1900) + "-";
	if (start_date.tm_mon + 1 <= 9)
		info += "0";
	info += std::to_string(start_date.tm_mon + 1) + "-";
	if (start_date.tm_mday <= 9)
		info += "0";
	info += std::to_string(start_date.tm_mday) + " ";
	if (start_date.tm_hour <= 9)
		info += "0";
	info += std::to_string(start_date.tm_hour) + ":";
	if (start_date.tm_min <= 9)
		info += "0";

	info += std::to_string(start_date.tm_min) + ";" + end_city + ";";

	info += std::to_string(end_date.tm_year + 1900) + "-";
	if (end_date.tm_mon + 1 <= 9)
		info += "0";
	info += std::to_string(end_date.tm_mon + 1) + "-";
	if (end_date.tm_mday <= 9)
		info += "0";
	info += std::to_string(end_date.tm_mday) + " ";
	if (end_date.tm_hour <= 9)
		info += "0";
	info += std::to_string(end_date.tm_hour) + ":";
	if (end_date.tm_min <= 9)
		info += "0";

	info += ";" + std::to_string(capacity) + ";" + std::to_string(tickets_left);

	return info;
}

void railways_list::sort_by_date()
{
	std::sort(list_.begin(), list_.end(), [](railway r1, railway r2) -> bool
	{
		return mktime(&r1.start_date) < mktime(&r2.start_date);
	});
}