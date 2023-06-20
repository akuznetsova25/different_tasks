#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

enum Month
{
	jan = 1, feb, mar, apr, may, jun,
	jul, aug, sep, oct, nov, dec
};

void Days(int num, Month M)
{
	switch (num)
	{
	case(jan):
	case(mar):
	case(may):
	case(jul):
	case(aug):
	case(oct):
	case(dec):
		std::cout << "Amount of days: 31" << std::endl;
		break;
	case(apr):
	case(jun):
	case(sep):
	case(nov):
		std::cout << "Amount of days: 30" << std::endl;
		break;
	case(feb):
		std::cout << "Amount of days: 28" << std::endl;
		break;
	default:
		std::cout << "Typing error" << std::endl;
		break;
	}
}



int main()
{

	Month testMonth = jan;
	int number;
	std::cout << "Enter number of month: ";
	std::cin >> number;
	Days(number, testMonth);
	return 0;
}