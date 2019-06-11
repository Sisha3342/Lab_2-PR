#include "my_set.h"

struct test_struct
{
	char name[30];
	double price;


	test_struct() = default;
	test_struct(char name[30], double price)
	{
		strcpy_s(this->name, name);
		this->price = price;
	}

	test_struct(char name[30])
	{
		strcpy_s(this->name, name);
		price = 0;
	}

	friend std::ostream& operator<<(std::ostream& out, test_struct const& my_struct)
	{
		out << my_struct.name << " " << my_struct.price;

		return out;
	}
};

int compare(const void* a, const void* b)
{
	return strcmp(((test_struct*)a)->name, ((test_struct*)b)->name);
}

int reverse_compare(const void* a, const void* b)
{
	return strcmp(((test_struct*)b)->name, ((test_struct*)a)->name);
}

int main()
{
	test_struct A("hello world", 10);
	test_struct B("hello world", 20);
	test_struct C("print", 10);
	test_struct D("true", 123);
	
	test_struct* arr = new test_struct[3];
	arr[0] = A;
	arr[1] = B;
	arr[2] = C;

	test_struct* arr1 = new test_struct[3];
	arr1[0] = C;
	arr1[1] = B;
	arr1[2] = D;

	my_set<test_struct> m_set(arr, 3, compare);
	my_set<test_struct> m1_set(arr1, 3, compare);
	my_set<test_struct> m2_set(m_set | m1_set);
	my_set<test_struct> m3_set(m_set & m1_set);
	m2_set.sort(reverse_compare);
	std::cout << m2_set;

	if (m2_set.find(test_struct("print")))
	{
		std::cout << "LUL";
	}

	return 0;
}