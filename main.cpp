#include <iostream>
#include <vector>
#include <string>
#include "employee.h"
#include <algorithm>
#include <getopt.h>
#include <queue>
using namespace std;
// TODO: Implement -h -p flags
class coffee_payment
{
public:
	void get_options(int argc, char **argv);
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
	bool s_flag = false;
};

// reading the flag arguments
void coffee_payment::get_options(int argc, char **argv)
{
	int option_index = 0, option = 0;

	opterr = false;

	struct option longOpts[] = {{"help", no_argument, nullptr, 'h'},
								{"stats", no_argument, nullptr, 's'},
								{nullptr, 0, nullptr, '\0'}};

	while ((option = getopt_long(argc, argv, "qshb:e:o:clp", longOpts, &option_index)) != -1)
	{
		switch (option)
		{
		case 'h':
			cout << "The program will ask you about the following information:\n"
				 << "Total number of employees\n"
				 << "For employee, [employee's name] [employee's favorite coffee] [the cost of the coffee(without $ sign)] [number of times they have paid for coffee]"
				 << "(please seperate each information with a white space in between)";
			break;

		case 's':
			s_flag = true;
			break;

			cerr << "Error: invalid option" << endl;
			exit(1);
		}
	}
}

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

// function to print the specific priorities of employees
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
	if (s_flag)
	{
		print_stats();
	}
}

int main(int argc, char **argv)
{
	coffee_payment c;
	c.get_options(argc, argv);
	c.run();
	return 0;
}