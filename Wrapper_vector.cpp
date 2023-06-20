#include <iostream>
#include <vector>
#include <algorithm>


template <typename T>
class Container
{
public:
	Container(int new_size) : size(new_size)
	{
		array = new T[new_size];
	}

	Container() : size(0)
	{

	}

	~Container()
	{
		delete[] array;
	}
	
	T & operator[](std::size_t index)
	{
		return array[index];
	}

	std::size_t get_size()
	{
		return size;
	}

	void swap(std::size_t index_1, std::size_t index_2)
	{
		if (index_1 < 0 || index_2 < 0 || index_1 >= size || index_2 >= size)
		{
			std::cout << "Error! " << std::endl;
			return;
		}
		std::swap(array[index_1], array[index_2]);
	}

	void add(std::size_t index_1, std::size_t value)
	{
		if (index_1 < 0)
		{
			std::cout << "Error! " << std::endl;
			return;
		}
		else if (size == 0)
		{
			array = new T[size++];
		}
		else if (index_1 >= size)
		{
			T * array_1 = new T[index_1 + 1];
			for (auto i = 0U; i < size; ++i)
			{
				array_1[i] = array[i];
			}
			size = index_1 + 1;
		}
		else
		{
			array[index_1] = value;
		}
	}

	
	void operator=(T & array_1)
	{
		array = array_1;
		array_1 = nullptr;
	}

	void operator=(const T & array_1)
	{
		array = array_1;
	}

	void resize(std::size_t N)
	{
		if (N < size)
		{
			std::cout << "Error!" << std::endl;
			return;
		}
		else
		{
			T* array_1 = new T[N];
			for (auto i = 0U; i < size; ++i)
			{
				array_1[i] = array[i];
			}
			size = N;
		}
	}

private:
	T * array;
	std::size_t size;
};



int main()
{
	Container <int> massiv(5);
	massiv.add(0, 4);
	massiv.add(1, 5);
	massiv.add(7, 1);

	std::cout << massiv[1] << std::endl;

	std::cout << massiv.get_size() << std::endl;

	massiv.swap(0, 1);
	std::cout << massiv[0] << std::endl;
	std::cout << massiv[1] << std::endl;

	massiv.resize(10);
	std::cout << massiv.get_size() << std::endl;

	return 0;
}