#pragma once
#include <vector>
#include <algorithm>

template<typename T>
class my_class
{
	std::vector<T> objects_list;
public:
	my_class() = default;
	my_class(my_class const&) = delete;
	my_class(my_class &&) = delete;

	size_t get_count()
	{
		return objects_list.size();
	}

	T& operator[](int index)
	{
		return objects_list[index];
	}

	friend std::ostream& operator<<(std::ostream& out, my_class<T> const& my_list)
	{
		for (size_t i = 0; i < my_list.objects_list.size(); i++)
			out << my_list.objects_list[i] << std::endl;

		return out;
	}

	friend std::istream& operator>>(std::istream& in, my_class<T> & my_list)
	{
		std::string temp;

		std::getline(in, temp);

		if (!temp.empty())
		{
			my_list.objects_list.push_back(T(temp));
		}

		return in;
	}

	std::vector<T> compare_name(std::string const& str)
	{
		std::vector<T>::iterator temp = std::find_if(objects_list.begin(), objects_list.end(), [&str](T const& c)
		{
			int len1 = c.name.length(), len2 = str.length();
			int min_len = len1 <= len2 ? len1 : len2;

			return c.name.substr(0, min_len) == str.substr(0, min_len);
		});

		std::vector<T> found_names;

		while (temp != objects_list.end())
		{
			found_names.push_back(*temp);

			temp = std::find_if(++temp, objects_list.end(), [&str](T const& c)
			{
				int len1 = c.name.length(), len2 = str.length();
				int min_len = len1 <= len2 ? len1 : len2;

				return c.name.substr(0, min_len) == str.substr(0, min_len);
			});
		}

		return found_names;
	}

	void sort_()
	{
		std::sort(objects_list.begin(), objects_list.end(), [](T c1, T c2) -> bool
		{
			return c1 < c2;
		});
	}
};