#pragma once
#include <vector>
#include <string>

struct test_class
{
	std::string name;
	std::string second_name;
	int code;
	int year;

	test_class() = default;
	test_class(std::string info);
	bool operator<(test_class const& obj);
	friend std::ostream& operator<<(std::ostream& out, test_class const& obj);
};