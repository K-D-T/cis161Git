//Necessary files to help the program run, namepsace used for ease of access
#include<iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

//Main method used to run the program
int main(){

	//Various variables to help us capture values
	string name;
	double savingsRate = 0.0;
	double salary = 0.0;
	double savingsPerYear = 0.0;
	int count = 0;

	//Beginning of interaction capture name of employee 
	cout << "Enter name (q to quit): " << endl;
	cin >> name;

	//Main loop, if q is entered program stops running
	while(name != "q"){
		
		//more input; capture savings rate
		cout << "Enter savings rate: " << endl;
		cin >> savingsRate;

		//had to hack this together, iostream nneeds to be flushed to properly work at times
		while(!cin){
			string s;
			cin.clear();
			cin >> s;
			cout << "Invalid entry. Enter savings rate: ";
			cin >> savingsRate;
		}

		//Because of constraints in code, we had to check for  negatives and integer values
		//integer values are changed into percentages.
		if(savingsRate < 0)
			savingsRate = abs(savingsRate);
		if(savingsRate > 1.0){
			cout << "It was determined you entered a value greater than 1. ";
			cout << "We've taken the liberty of turning this into a percent."  << endl;
			savingsRate = (savingsRate / 100.0);
		}

		//Get salary
		cout << "Enter salary: " << endl;
		cin >> salary;
		
		//There's some stuff here that allows us to cleaar the IO stream
		//we dont' allow anything other positive integers/doubles	
		while(salary <= 0){
			string s;
			cin.clear();
			cin >> s;
			cout << "You need to input a value that makes sense and is over $0: " << endl;
			cin >> salary;
		}

		cout << "The account values for " << name << " are: " << endl;
		
		//Easy way to iterate through 10 years of accoutn values.
		while(count < 10){
			savingsPerYear = (savingsPerYear * 1.08) + (savingsRate * salary) * 1.08;
			cout << fixed << setprecision(2) << savingsPerYear << endl;
			count++;
		}
		//Reset the counters	
		count = 0;
		savingsPerYear = 0.0;
		cout << "Enter name (q to quit): " << endl;
		cin >> name;
	}

	cout << "End Of Program. Goodbye." << endl;

	return 0;

}
