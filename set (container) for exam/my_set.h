#pragma once
#include <cstdlib>
#include <iostream>

template<typename T>
class my_set
{
	size_t count;
	size_t max_size;
	T* objects_set;
	int(*compare_func)(const void* a, const void* b);
	int(*sort_compare_func)(const void* a, const void* b);

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

	void append_for_intersection(T object, my_set set_1, my_set set_2)
	{
		if (set_1.find(object) &&
			set_2.find(object) &&
			(find(object) == nullptr))
		{
			if (max_size == count)
			{
				reallocate_memory();
			}

			objects_set[count++] = object;
		}

		sort_compare_func = nullptr;
	}


public:
	my_set()
	{
		count = max_size = 0;
		compare_func = nullptr;
		objects_set = nullptr;
		sort_compare_func = nullptr;
	}

	explicit my_set(int(*compare_func)(const void*, const void*))
	{
		this->compare_func = compare_func;
		sort_compare_func = nullptr;
		count = max_size = 0;
		objects_set = nullptr;
	}

	explicit my_set(T* objects_list, size_t objects_count, int(*compare_func)(const void*, const void*))
	{
		this->compare_func = compare_func;
		sort_compare_func = nullptr;
		max_size = objects_count;
		count = 0;

		objects_set = new T[max_size];

		for (int i = 0; i < max_size; i++)
			append(objects_list[i]);
	}

	my_set(my_set && set) noexcept
	{
		count = set.count;
		max_size = set.max_size;
		objects_set = set.objects_set;
		compare_func = set.compare_func;
		sort_compare_func = set.sort_compare_func;
		set.compare_func = nullptr;
		set.objects_set = nullptr;
	}

	my_set(my_set const& set)
	{
		count = set.count;
		max_size = set.max_size;
		objects_set = new T[max_size];
		compare_func = set.compare_func;
		sort_compare_func = set.sort_compare_func;
		for (int i = 0; i < count; i++)
		{
			objects_set[i] = set.objects_set[i];
		}
	}

	size_t get_size()
	{
		return count;
	}


	my_set& operator=(my_set const& set)
	{
		count = set.count;
		max_size = set.max_size;
		compare_func = set.compare_func;
		sort_compare_func = set.sort_compare_func;
		delete[] objects_set;
		objects_set = new T[max_size];

		for (int i = 0; i < count; i++)
		{
			objects_set[i] = set.objects_set[i];
		}

		return *this;
	}


	void append(T object)
	{
		if (lfind(&object, objects_set, &count, sizeof(T), compare) == nullptr)
		{
			if (max_size == count)
			{
				reallocate_memory();
			}

			objects_set[count++] = object;
		}
		sort_compare_func = nullptr;
	}

	T& operator[](int index) const
	{
		if (index >= count || index < 0)
			throw std::invalid_argument("No element with this index");

		return objects_set[index];
	}

	void sort(int(*compare_function)(const void* a, const void* b))
	{
		qsort(objects_set, count, sizeof(T), compare_function);
		sort_compare_func = compare_function;
	}

	T* find(T const& key) 
	{
		if (sort_compare_func)
		{
			return static_cast<T*>(bsearch(&key, objects_set, count, sizeof(T), sort_compare_func));
		}
		else
		{
			return static_cast<T*>(lfind(&key, objects_set, &count, sizeof(T), compare_func));
		}
	}

	friend my_set operator|(my_set const& set_1, my_set const& set_2)
	{
		if (set_1.compare_func != set_2.compare_func)
			throw std::invalid_argument("Can't unite sets with different compare functions");

		my_set<T> temp(set_1);
		for (int i = 0; i < set_2.count; i++)
			temp.append(set_2[i]);

		return my_set(temp);
	}
	
	friend my_set operator&(my_set const& set_1, my_set const& set_2)
	{
		if (set_1.compare_func != set_2.compare_func)
			throw std::invalid_argument("Can't intersect sets with different compare functions");

		my_set<T> temp(set_1.compare_func);
		for (int i = 0; i < set_1.count; i++)
			temp.append_for_intersection(set_1[i], set_1, set_2);
		for (int i = 0; i < set_2.count; i++)
			temp.append_for_intersection(set_2[i], set_1, set_2);

		return my_set(temp);
	}

	friend std::ostream& operator<<(std::ostream& out, my_set const& set)
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