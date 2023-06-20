#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>



struct Date
{
	int year : 13;
	int month : 5;
	int day : 6;
	int hour : 6;
	int minute : 7;
	int second : 7;
	int millisecond : 11;
};



int main()
{
	Date Date_Time;
	int i;

	std::cout << "Enter year: ";
	std::cin >> i;
	Date_Time.year = i;

	std::cout << "Enter month: ";
	std::cin >> i;
	Date_Time.month = i;

	std::cout << "Enter day: ";
	std::cin >> i;
	Date_Time.day = i;

	std::cout << "Enter hours: ";
	std::cin >> i;
	Date_Time.hour = i;

	std::cout << "Enter minute: ";
	std::cin >> i;
	Date_Time.minute = i;

	std::cout << "Enter second: ";
	std::cin >> i;
	Date_Time.second = i;

	std::cout << "Enter millisecond: ";
	std::cin >> i;
	Date_Time.millisecond = i;

	std::cout << "You entered the date: " << Date_Time.day << "." << Date_Time.month << "." << Date_Time.year << "   ";
	std::cout << Date_Time.hour << ":" << Date_Time.minute << ":" << Date_Time.second << ":" << Date_Time.millisecond << std::endl;

	return 0;
}