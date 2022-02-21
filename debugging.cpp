#include <iostream>
//this is necessary for linking output, std is shortened for standard, the cause of the 'use of undeclared identifier xyz; error

using namespace std;
// the cause of the undeclared identifier 'cin/cout' error

int main(){
	int hourlyWage;
	//second variable had an error associated with declaration
	
	int _1YearSalary; // variable name has to start with letter or underscore, can't contain a number as well.
	// expected unqualified-id : doesn't like variable declaration, numbers cause error.
	
	cout << "What is the hourly wage?" << endl;
	cin >> hourlyWage;
	
	_1YearSalary = hourlyWage * 40 * 50;
	
	cout << "Annual salary is: " << _1YearSalary << endl;
	
	return 0;
	//minor error about ensuring to end all statements with a semicolon. Cause of the expected ';' error
}
