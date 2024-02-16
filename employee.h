#include <iostream>
#include <string>
#include <random>

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
	mutable default_random_engine generator;

	bool operator()(const employee_priority &employee_a, const employee_priority &employee_b) const
	{
		if (employee_a.priority == employee_b.priority)
		{
			uniform_int_distribution<int> distribution(0, 1);
			return distribution(generator) == 0; // Randomly choose between the two when priorities are equal
		}
		else
		{
			return employee_a.priority > employee_b.priority;
		}
	}
};