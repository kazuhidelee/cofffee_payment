#include <iostream>
#include <vector>
#include <string>
#include "employee.h"
#include <algorithm>
#include <getopt.h>
#include <queue>
using namespace std;

class coffee_payment
{
public:
	void run();
	void print_stats();

private:
	vector<employee> people;
	void read_info();
	void calc_priority();
	void get_result();
	int num_people = 0;
	double total_price = 0;
	priority_queue<employee_priority, vector<employee_priority>, employee_comparator> pq;
};

//	function to read in employee's info
void coffee_payment::read_info()
{
	employee temp;
	cout << "please enter the total number of employees\n";
	cin >> num_people;
	for (size_t i = 0; i < num_people; ++i)
	{
		cout << "Please enter the employee's information in the format and seperate items by space:"
			 << "[Name] [Favorite Drink] [Drink's price] [number of times paid for coffee] \n";
		cin >> temp.name;
		cin >> temp.favoriteDrink;
		cin >> temp.drinkPrice;
		total_price += temp.drinkPrice;
		cin >> temp.num_paid;
		people.push_back(temp);
	}
}

// function to calculate the priority to pay for each employee
void coffee_payment::calc_priority()
{
	employee_priority temp;
	for (size_t i = 0; i < num_people; ++i)
	{
		temp.priority = people[i].num_paid * total_price + (total_price - people[i].drinkPrice);
		temp.indx = i;
		pq.push(temp);
	}
}

// function to announce the result
void coffee_payment::get_result()
{
	employee_priority pay;
	pay = pq.top();
	cout << "Based on the calculations, " << people[pay.indx].name << " "
		 << "should pay for coffee this time\n";
	cout << "Thank you " << people[pay.indx].name << "!\n";
}

void coffee_payment::print_stats()
{
	employee_priority pay;
	for (size_t i = 0; i < num_people; ++i)
	{
		pay = pq.top();
		cout << "name: " << people[pay.indx].name << " priority: " << pay.priority << "\n";
		pq.pop();
	}
	cout << total_price << endl;
}

// driver function
void coffee_payment::run()
{
	read_info();
	calc_priority();
	get_result();
	print_stats();
}

int main()
{
	coffee_payment c;
	c.run();
	return 0;
}