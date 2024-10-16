#include <iostream>



class smart_array
{
public:
	smart_array(int a);
	~smart_array();
	smart_array(const smart_array& other);
	void add_element(int value);
	int get_element(int index);
	smart_array& operator = (const smart_array& other);
private:
	int size;
	int* arr;
	int i;

};

smart_array::smart_array(int a)
{
	size = a;
	arr = new int[size];
	i = 0;
}

smart_array::~smart_array()
{
	delete[] arr;
}

void smart_array::add_element(int value)
{
	if (i < size)
	{
		arr[i] = value;
		++i;
	}
	else
	{
		throw std::exception("array overflow");
	}
}

int smart_array::get_element(int index)
{
	if (index <= i)
	{
		return arr[index];
	}
	else
	{
		throw std::exception("value not initialized");
	}
}

smart_array& smart_array::operator = (const smart_array& other)
{
	delete[] arr;
	size = other.size;
	i = 0;
	arr = new int[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = other.arr[i];
	}
	return *this;

}

smart_array::smart_array(const smart_array &other)
{
	size = other.size;
	i = 0;
	arr = new int[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = other.arr[i];
	}
}

int main()
{
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}