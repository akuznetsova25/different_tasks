#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>



struct Element
{
	Element(const std::string & n, int a, double r, int n_a)
	{
		name = n;
		atomic_number = a;
		relative_atomic_mass = r;
		numberof_atoms = n_a;
	}

	~Element()
	{};

	std::string name;
	int atomic_number;
	double relative_atomic_mass;
	int numberof_atoms;

	double m_mass()
	{
		return relative_atomic_mass * numberof_atoms;
	}
};



int main()
{
	std::vector <Element> elements;

	elements.emplace_back("molybdenum", 42, 100, 1);
	elements.emplace_back("sulfur", 16, 32, 8);
	elements.emplace_back("chlorine", 17, 35.5, 2);
	elements.emplace_back("iodine", 53, 127, 2);

	std::cout << "molecular mass: " << std::endl;

	for (auto i = 0; i < elements.size(); ++i)
	{
		std::cout << elements[i].name << ": " << elements[i].m_mass() << std::endl;
	}

	return 0;
}