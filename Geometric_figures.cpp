#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>



std::pair<double, double> foo(double a, double b) 
{
	return std::make_pair(a, b);
}



double distance(std::pair<double, double> a, std::pair<double, double> b)
{
	return std::sqrt(std::pow((a.second - b.second), 2) + pow((a.first - b.first), 2));
}



class Shape
{
public:
	virtual void output() const = 0;
	virtual double perimeter() const = 0;
	virtual double area() const = 0;
	virtual ~Shape() = default;

	std::vector <std::pair<double, double>> points;
	const double pi = 3.14;
};



class Triangle : public Shape
{
public:
	Triangle(std::pair<double, double> a, std::pair<double, double> b, std::pair<double, double> c) : Shape(), 
		ab(distance(a, b)), bc(distance(b, c)), ac(distance(a, c))
	{
		points.push_back(a);
		points.push_back(b);
		points.push_back(c);
		
	}

	Triangle() {}

	double get_ab()
	{
		return ab;
	}

	double get_bc()
	{
		return bc;
	}

	double get_ac()
	{
		return ac;
	}
	
	virtual double perimeter() const override
	{
		
		double perimeter = ab + bc + ac;
		return perimeter;
	}

	virtual double area() const override
	{
		double p = perimeter() / 2;
		double s = sqrt(p * (p - ab) * (p - ac) * (p - bc));
		return s;
	}

	virtual void output() const override
	{
		std::cout << "Triangle" << std::endl;
		std::cout << "Area: " << area() << std::endl;
		std::cout << "Perimeter: " << perimeter() << std::endl;
	};

private:
	double ab;
	double bc;
	double ac;
};



class Rectangle : public Shape
{
public:
	Rectangle(std::pair<double, double> a, std::pair<double, double> b, std::pair<double, double> c) : Shape(),
		ab(distance(a, b)), bc(distance(b, c))
	{
		points.push_back(a);
		points.push_back(b);
		points.push_back(c);
	}

	Rectangle() {}

	double get_bc()
	{
		return bc;
	}

	double get_ac()
	{
		return ab;
	}

	virtual double perimeter() const override
	{
		double perimeter = 2 * (ab + bc);
		return perimeter;
	}

	virtual double area() const override
	{
		double square = ab * bc;
		return square;
	}

	virtual void output() const override
	{
		std::cout << "Rectagle" << std::endl;
		std::cout << "Area: " << area() << std::endl;
		std::cout << "Perimeter: " << perimeter() << std::endl;
	};

private:
	double ab;
	double bc;
};



class Square : public Rectangle
{
public:
	Square(std::pair<double, double> a, std::pair<double, double> b) : ab(distance(a, b))
	{
		points.push_back(a);
		points.push_back(b);
	}

	Square() {}

	double get_ab()
	{
		return ab;
	}

	virtual double perimeter() const override
	{
		double perimeter = 4 * ab;
		return perimeter;
	}

	virtual double area() const override
	{
		double square = ab * ab;
		return square;
	}

	virtual void output() const override
	{
		std::cout << "Square" << std::endl;
		std::cout << "Area: " << area() << std::endl;
		std::cout << "Perimeter: " << perimeter() << std::endl;
	};

private:
	double ab;
};



class Ellipse : public Shape
{
public:
	Ellipse(std::pair<double, double> centre, std::pair<double, double> a_1, std::pair<double, double> b_1) : Shape(), 
		a(distance(centre, a_1)), b(distance(centre, b_1))
	{
		points.push_back(centre);
		points.push_back(a_1);
		points.push_back(b_1);
	}

	Ellipse(){}

	double get_a()
	{
		return a;
	}

	double get_b()
	{
		return b;
	}

	virtual double area() const override
	{
		double square = pi * a * b; 
		return square;
	}

	virtual double perimeter() const override
	{
		double perimeter = 4 * (pi * a * b + pow((a - b), 2)) / (a + b);
		return perimeter;
	}

	virtual void output() const override
	{
		std::cout << "Ellipse" << std::endl;
		std::cout << "Square: " << area() << std::endl;
		std::cout << "Perimeter: " << perimeter() << std::endl;
	};

private:
	double a;
	double b;
};



class Circle : public Ellipse
{
public:
	Circle(std::pair<double, double> centre_c, std::pair<double, double> p) : r(distance(centre_c, p))
	{
		points.push_back(centre_c);
		points.push_back(p);
	}

	Circle() {}

	double get_r()
	{
		return r;
	}

	virtual double area() const override
	{
		double square = pi * pow(r, 2);
		return square;
	}

	virtual double perimeter() const override
	{
		double perimeter = 2 * pi * r;
		return perimeter;
	}

	virtual void output() const override
	{
		std::cout << "Circle" << std::endl;
		std::cout << "Area: " << area() << std::endl;
		std::cout << "Perimeter: " << perimeter() << std::endl;
	};

private:
	double r;
};





int main()
{
	std::vector <Shape*> shapes;

	Ellipse* ellipse = new Ellipse({ 0.0, 0.0 }, { 3.0, 0.0 }, { 0.0, 5.0 });
	Rectangle* rectangles = new Rectangle({1.0, 1.0}, {2.0, 1.0}, {2.0, 5.0});
	Triangle* triangles = new Triangle({ 0.0, 0.0 }, { 3.0, 0.0 }, { 0.0, 4.0 });
	Square* squares = new Square({ 0.0, 0.0 }, {1.0, 0.0});
	Circle* circles = new Circle({0.0, 0.0}, {0.0, 2.0});

	shapes.push_back(squares);
	shapes.push_back(triangles);
	shapes.push_back(rectangles);
	shapes.push_back(ellipse);
	shapes.push_back(circles);

	for (auto i = 0U; i < shapes.size(); ++i)
	{
		shapes[i]->output();
		std::cout << std::endl;
	}

	return 0;
}