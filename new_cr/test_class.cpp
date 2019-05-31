#include "test_class.h"

bool test_class::operator<(test_class const& obj)
{
	return name < obj.name;
}

test_class::test_class(std::string info)
{
	std::vector<std::string> temp;
	int pos2 = 0;
	std::string temp_str = info;

	while (pos2 != -1)
	{
		pos2 = temp_str.find(' ');
		temp.push_back(temp_str.substr(0, pos2));
		temp_str = temp_str.substr(pos2 + 1);
	}

	name = temp[0];
	second_name = temp[1];
	code = std::stol(temp[2]);
	year = std::stol(temp[3]);
}

std::ostream& operator<<(std::ostream& out, test_class const& obj)
{
	out << obj.name << " " << obj.second_name << " " << obj.code << " " << obj.year;

	return out;
}