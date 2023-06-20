#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <cmath>


double calculate(const std::function<double(double, double)> lyambda, double a, double b)
{
	double res = lyambda(a, b);
	return res;
}



int main()
{
	double x, y;

	std::cout << "Enter x: " << std::endl;
	std::cin >> x;
	std::cout << "Enter y: " << std::endl;
	std::cin >> y;

	auto lyambda_1 = [](double x, double y) { return x + y; };
	auto lyambda_2 = [](double x, double y) { return x * y; };
	auto lyambda_3 = [](double x, double y) { return sqrt(x * y); };
	auto lyambda_4 = [](double x, double y) { return log(x + y); };

	std::vector <std::function <double(double, double)>> L = { lyambda_1, lyambda_2, lyambda_3, lyambda_4 };
	std::cout << "Results: " << std::endl;
	for (auto l : L)
	{
		double res = calculate(l, x, y);
		std::cout << res << std::endl;
	}

	return 0;
}
