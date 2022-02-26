#include <iostream>
using namespace std;

int main(){

	//Various Variables to represent constants, hours in a week, wage, upper and lower salary  
	const int MAX_HOURS_IN_WEEK=168;
	const int MAX_WAGE=100;
	const int LOWER_SALARY=200;
	const int UPPER_SALARY=800;

	// variables to represent values, we'll need
	int hourlyWage;
	int workHoursPerWeek;
	int weeklySalary;

	cout << "How many hours do you work per week?" << endl;
	cin >> workHoursPerWeek;

	if(workHoursPerWeek <= 0 || workHoursPerWeek > MAX_HOURS_IN_WEEK){
		cout << "Invalid number of hours per week." << endl;
		return -1;
	}
	
	cout << "What is your hourly wage?" << endl;
	cin >> hourlyWage;
	if(hourlyWage > MAX_WAGE){ 
		cout << "An hourly wage greater than 100 requires executive approval." << endl;
		//Probably shouldn't have done this, but this line made me believe that no wage
		////should be greater than MAX_WAGE
		while(hourlyWage > MAX_WAGE){
			cout << "What is your hourly wage?" << endl;
			cin >> hourlyWage;
		}
	//Added zero as an invalid wage, it just made sense to end the progrma if there's no wage	
	}else if(hourlyWage <= 0){
		cout << "Invalid hourly wage." << endl;
		return -1;
	}
	weeklySalary = hourlyWage * workHoursPerWeek;
	if(weeklySalary < LOWER_SALARY){
		cout << "The weekly salary is less than 200." << endl;
	}
	//Had to change it to else if, It would run into an error with the previous conditional.
	else if(weeklySalary >= LOWER_SALARY && weeklySalary <= UPPER_SALARY){
		cout << "The weekly salary is between 200 and 800." << endl;
	}else{
		cout << "The weekly salary is greater than 800." << endl;
	}

	return 0;
}
