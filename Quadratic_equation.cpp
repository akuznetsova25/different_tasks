#include <iostream>
#include <cmath>


int main()
{
	double a, b, c;
	std::cout << "Enter a: ";
	std::cin >> a;
	std::cout << "Enter b: ";
	std::cin >> b;
	std::cout << "Enter c: ";
	std::cin >> c;
	double D = b * b - 4.0 * a * c;
	if (a!= 0.0) 
	{
		if (D > 0.0)
		{
			std::cout << "x1 = " << (-b + sqrt(D)) / (2.0 * a) << std::endl;
			std::cout << "x2 = " << (-b - sqrt(D)) / (2.0 * a) << std::endl;
		}
		else if (D == 0.0)
		{
			std::cout << "x = " << -b / (2.0 * a) << std::endl;
		}
		else
		{
			std::cout << "The equation has no solutions";
		}
	}
	else
	{
		if (b == 0.0)
		{
			if (c == 0.0)
			{
				std::cout << "The solution of the equation is the entire coordinate plane";
			}
			else
			{
				std::cout << "The equation has no solutions";
			}
		}
		else
		{
			double res = -c / b;
			std::cout << "x = " << (res == 0.0 ? 0.0 : res) << '\n';
		}
	}
	return 0;

}