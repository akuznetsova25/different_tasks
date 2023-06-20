#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>



int main()
{
	
	std::vector <int> my_vec = {6, 1, 5, 2, 4, 3};
	
	std::cout << "Elements of vector: " << std::endl;
	for (auto a : my_vec)
	{
		std::cout << a << std::endl;
	}

	auto lyambda_1 = [](int i, int j) {	return i < j; };
	auto lyambda_2 = [](int i, int j) {	return i > j; };

	std::sort(my_vec.begin(), my_vec.end(), lyambda_1);

	std::cout << "Elements of vector (using lyambda_1): " << std::endl;
	for (auto a : my_vec)
	{
		std::cout << a << std::endl;
	}

	std::sort(my_vec.begin(), my_vec.end(), lyambda_2);

	std::cout << "Elements of vector (using lyambda_2): " << std::endl;
	for (auto a : my_vec)
	{
		std::cout << a << std::endl;
	}

	return 0;
}