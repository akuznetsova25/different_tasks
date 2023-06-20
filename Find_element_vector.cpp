#include <iostream>
#include <vector>
#include <cmath>



int main()
{
	std::size_t size;
	std::cout << "Enter size of vector:" << std::endl;
	std::cin >> size;
	std::cout << "Enter elements of vector:" << std::endl;
	std::vector<double> myVector(size, 0);
	for (auto& element : myVector)
	{
		std::cin >> element;
	}

	for (int i = 1; i < myVector.size(); ++i)
	{
		for (int j = i; j > 0 && myVector[j] < myVector[j - 1]; --j)
		{
			std::swap(myVector[j], myVector[j - 1]);
		}
	}

	double target_value;
	std::cout << "Enter target value: " << std::endl;
	std::cin >> target_value;
	int r = myVector.size() - 1;
	int l = 0;
	while (l <= r)
	{
		int m = std::floor((r + l)/2);
		if (myVector[m] < target_value)
		{
			l = m + 1;
		}
		else if (myVector[m] > target_value)
		{
			r = m - 1;
		}
		else 
		{
			std::cout << "Search item index: " << m << std::endl;
			break;
		}
	}
	if (l - r > 0)
	{
		std::cout << "There is no required element" << std::endl;
	}

	return 0;

}