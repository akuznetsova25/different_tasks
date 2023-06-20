#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

struct Lesson;

struct Student
{
	Student(const std::string& n, double a)
	{
		name = n;
		average_score = a;
	}

	~Student()
	{}

	std::string name;
	double average_score;

	std::vector<Lesson*> l_ptr;
};


struct Lesson
{
	Lesson(const std::string& t, int c, double h)
	{
		name_l = t;
		classroom = c;
		hours = h;
	}

	~Lesson()
	{}

	std::string name_l;
	int classroom;
	double hours;

	std::vector<Student*> st_ptr;
};



int main()
{
	std::vector <Student> students;
	std::vector <Lesson> lessons;

	students.emplace_back("Sagitova", 7.5);
	students.emplace_back("Bykoff", 6.8);
	students.emplace_back("Fukin", 9.5);
	students.emplace_back("Talysheva", 8.8);

	lessons.emplace_back("Semiconduct", 516, 3.5);
	lessons.emplace_back("CMech", 512, 4.5);
	lessons.emplace_back("Gas_hydr", 420, 2.5);
	lessons.emplace_back("CompMath", 316, 4.5);
    
	
	for (auto i = 0; i < students.size(); ++i) 
	{
		for (auto j = 0; j < students.size(); ++j)
		{
			students[i].l_ptr.push_back(&lessons[j]);
			lessons[i].st_ptr.push_back(&students[j]);
		}
	}

	std::cout << "Course hours:" << std::endl;
	std::cout << students[0].name << ": " << students[0].l_ptr[1]->hours + students[0].l_ptr[2]->hours << std::endl;
	std::cout << students[1].name << ": " << students[1].l_ptr[3]->hours << std::endl;
	std::cout << students[2].name << ": " << students[2].l_ptr[0]->hours + students[2].l_ptr[1]->hours +
		students[1].l_ptr[2]->hours + students[1].l_ptr[3]->hours << std::endl;

	std::cout << students[3].name << ": " << students[3].l_ptr[0]->hours + students[3].l_ptr[2]->hours << std::endl;
	std::cout << std::endl;

	std::cout << "Attendance:" << std::endl;
	std::cout << lessons[0].name_l << ": " << lessons[0].st_ptr[2]->name << std::endl;
	std::cout << lessons[1].name_l << ": " << lessons[1].st_ptr[0]->name << ", " 
		<< lessons[1].st_ptr[2]->name << std::endl;
	std::cout << lessons[2].name_l << ": " << lessons[2].st_ptr[3]->name << ", " 
		<< lessons[2].st_ptr[2]->name  << std::endl;
	std::cout << lessons[3].name_l << ": " << lessons[3].st_ptr[1]->name << std::endl;

	return 0;
}