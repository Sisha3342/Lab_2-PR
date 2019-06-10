#pragma once
#include <cstdlib>
#include <iostream>

template<typename T>
class my_set
{
	size_t count;
	size_t max_size;
	T* objects_set;
	int(*compare)(const void* a, const void* b);

	void reallocate_memory()
	{
		max_size += 10;
		T* temp_array = new T[max_size];

		for (int i = 0; i < count; i++)
			temp_array[i] = objects_set[i];

		delete[] objects_set;

		objects_set = new T[max_size];
		for (int i = 0; i < count; i++)
			objects_set[i] = temp_array[i];

		delete[] temp_array;
	}

	void append_for_intersection(T object, my_set<T> set_1, my_set<T> set_2)
	{
		if (bsearch(&object, set_1.objects_set, set_1.count, sizeof(T), set_1.compare) && 
			bsearch(&object, set_2.objects_set, set_2.count, sizeof(T), set_1.compare) && 
			(bsearch(&object, objects_set, count, sizeof(T), set_1.compare) == nullptr))
		{
			if (max_size == count)
			{
				reallocate_memory();
			}

			objects_set[count++] = object;
		}
	}


public:
	my_set()
	{
		count = max_size = 0;
		compare = nullptr;
		objects_set = nullptr;
	}

	my_set(T* objects_list, size_t objects_count, int(*compare)(const void*, const void*))
	{
		this->compare = compare;
		max_size = objects_count;
		count = 0;

		objects_set = new T[max_size];

		for (int i = 0; i < max_size; i++)
			append(objects_list[i]);
	}

	my_set(my_set<T> && set) noexcept
	{
		count = set.count;
		max_size = set.max_size;
		objects_set = set.objects_set;
		compare = set.compare;
		set.compare = nullptr;
		set.objects_set = nullptr;
	}

	my_set(my_set<T> const& set)
	{
		count = set.count;
		max_size = set.max_size;
		objects_set = new T[max_size];
		compare = set.compare;
		for (int i = 0; i < count; i++)
		{
			objects_set[i] = set.objects_set[i];
		}
	}

	my_set<T>& operator=(my_set<T>const& set)
	{
		return my_set(set.objects_set, set.count, set.compare);
	}


	void append(T object)
	{
		if (bsearch(&object, objects_set, count, sizeof(T), compare) == nullptr)
		{
			if (max_size == count)
			{
				reallocate_memory();
			}

			objects_set[count++] = object;
		}
	}

	T& operator[](int index) const
	{
		if (index >= count || index < 0)
			throw std::invalid_argument("No element with this index");

		return objects_set[index];
	}

	friend my_set<T> operator|(my_set<T> const& set_1, my_set<T> const& set_2)
	{
		if (set_1.compare != set_2.compare)
			throw std::invalid_argument("Can't unite sets with different compare functions");

		my_set<T> temp(set_1);
		for (int i = 0; i < set_2.count; i++)
			temp.append(set_2[i]);

		return my_set(temp);
	}

	friend my_set<T> operator&(my_set<T> const& set_1, my_set<T> const& set_2)
	{
		if (set_1.compare != set_2.compare)
			throw std::invalid_argument("Can't unite sets with different compare functions");

		my_set<T> temp;
		for (int i = 0; i < set_1.count; i++)
			temp.append_for_intersection(set_1[i], set_1, set_2);
		for (int i = 0; i < set_2.count; i++)
			temp.append_for_intersection(set_2[i], set_1, set_2);

		return my_set(temp);
	}

	friend std::ostream& operator<<(std::ostream& out, my_set<T> const& set)
	{
		for (int i = 0; i < set.count; i++)
			out << set[i] << "\n";

		return out;
	}


	virtual ~my_set()
	{
		delete[] objects_set;
	}
};
