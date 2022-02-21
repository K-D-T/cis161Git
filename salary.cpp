#include <iostream>
//used for input/output

#include <iomanip>
//used to access set precision

using namespace std;
//used to link cin/cout

//main method used to run the program.
int main(){

	//most variables are set to double to represent a more accurate portrayal
	//variable to represent hourly wage of employee
	double hourlyWage;
	
	//variable to represent hours worked
	double workHoursPerWeek;
	
	//variable to represent how much money is accumulated through the week.
	double weeklySalary;
	
	//variable to represent how much money is made through the year.
	double annualSalary;
	
	//variable to represent amount of weeks
	const int year = 52;

	//Output readable text for input, pass value into workHoursPerWeek
	cout << "How many hours do you work per week?" << endl;
	cin >> workHoursPerWeek;

	//output readable text for input, pass value into hourlyWage
	cout << "What is your hourly wage?" << endl;
	cin >> hourlyWage;

	//calculate weekly salary based on hourly wage  * hours per week
	weeklySalary = hourlyWage * workHoursPerWeek;
	cout << "Weekly salary is: ";
	cout << fixed << setprecision(2) << weeklySalary << endl;

	//calculute annual salary based on weekly salary by year
	annualSalary = weeklySalary * year;  
	cout << "Annual salary is: ";
	cout << fixed << setprecision(2) << annualSalary << endl;

	//Used to close out the program
	return 0;
}
