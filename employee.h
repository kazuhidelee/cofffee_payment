#include <iostream>
#include <string>

using namespace std;

// A struct that represent an employee
struct employee
{
	string name;
	string favoriteDrink;
	double drinkPrice;
	int num_paid;
};

// A struct that represnet each employee's priority in paying for the coffee
struct employee_priority
{
	size_t indx;
	double priority;
};

// Comparator that compares employees' priority in paying (needed for priority queue)
struct employee_comparator
{
	bool operator()(const employee_priority &employee_a, const employee_priority &employee_b) const
	{
		return employee_a.priority > employee_b.priority;
	}
};