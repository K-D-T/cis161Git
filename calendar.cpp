#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
//A bucnh of helper functions to help out



//Checks for leap year based on alorgithm for leap year
bool isLeapYear(int year){
	if(year % 4 != 0){
		return false;
	}else if(year % 4 == 0 && year % 100 == 0 &&  year % 400 != 0){
		return false;
	}
	return true;

}

//If the value is zero it's an invalid string
int numberPerMonth(string month){
	if(month == "january" || month == "march" || month == "may" || 
			month  == "july" || month == "august" ||
		       	month == "october" || month == "december"){
		return 31;
	}else if(month == "june" || month == "september" || month == "november"){
		return 30;
	}else if(month == "february"){
		return 28;
	}		
	return 0;
}

//This function allows any string and returns it, there is nothing to validate its a specific month
//that's handdled in a helper function, also strips whitespace and sets to lowercase
string validateMonthInput(string& s){
	int ret = 0;
	cout << "Enter a month: " << endl;
	cin >> s;
	while(!cin){
		string ex;
		cin.clear();
		cin >> ex;
		cout << "Enter a month: " << endl;
		cin >> s;
	}
	s.erase(remove(s.begin(),s.end(), ' '), s.end());
	while(ret < s.length()){
		s[ret] = tolower(s[ret]);
		ret++;
	}

	return s;
}

//This only allows numbers, negatives are okay to represent BCE
int validateYearInput(int& i){
	int val = 0; 
	cout << "Enter a year, negative can represent B.C. or B.C.E. : " << endl;
	cin >> val;
	while(!cin){
		string s;
		cin.clear();
		cin >> s;
		cout << "Enter a year, negative can represent B.C. or B.C.E. : " << endl;
		cin >> val;
	}
	return val;
}

// This function is controls the action, it allows us to call it determining number of months
void start(int& year, int& numDays, string& month){
	year = validateYearInput(year);
	month = validateMonthInput(month);
	numDays = numberPerMonth(month);
	while(numDays == 0){
		cout << "The string you entered for month, unfortunately isn\'t a month." << endl; 
		month = validateMonthInput(month);
		numDays = numberPerMonth(month);
	}
	if(month == "february" && isLeapYear(abs(year))){
		numDays = numDays + 1;
	}
}

//Because i'm using vim;I'm 
void AutomatedTestingMonth(){
	string month;
	int year = 0;
	int count = 0; 
	int pass = 0; 
	int fail = 0;
	month = "random";
	year = numberPerMonth(month);
	if(year == 0)
		pass++;
	count++;
	month = "january";
	year = numberPerMonth(month);
	if(year != 0)
		pass++;
	count++;
	month = "december";
	year = numberPerMonth(month);
	if(year != 0)
		pass++;
	count++;
	month = "blah";
	year = numberPerMonth(month);
	if(year == 0)
		pass++;
	count++;
	month = "march";
	year = numberPerMonth(month);
	if(year != 0)
		pass++;
	count++;
	month = "may";
	year = numberPerMonth(month);
	if(year != 0)
		pass++;
	count++;
	month = "october"; 
	year = numberPerMonth(month);
	if(year != 0)
		pass++;
	count++;

	if(count == pass + fail){
		cout << "All tests passed, " << pass << " tests passed" << endl;
	}else{
		cout << "Some tests failed" << endl;
	}

}

void TestingLeapYear(){
	int year = 0;
	int count = 0;
	int fail = 0;
	int wrong = 0;
	(isLeapYear(2000)) ? count++ : fail++;
	(isLeapYear(2005)) ? count++ : fail++;
	wrong++;
	(isLeapYear(2009)) ? count++ : fail++;
	wrong++;
	(isLeapYear(-4)) ? count++ : fail++;
	(isLeapYear(8)) ? count++ : fail++;
	(isLeapYear(2016)) ? count++ : fail++;
	(isLeapYear(1045)) ? count++ : fail++;
	wrong++;
	(isLeapYear(1018)) ? count++ : fail++;
	wrong++;
	(isLeapYear(36)) ? count++ : fail++;
	(isLeapYear(2020)) ? count++ : fail++;
	(isLeapYear(1995)) ? count++ : fail++;
	wrong++;
	(isLeapYear(1937)) ? count++ : fail++;
	wrong++;
	(isLeapYear(1949)) ? count++ : fail++;
	wrong++;
	(isLeapYear(1997)) ? count++ : fail++;
	wrong++;
	(isLeapYear(90)) ? count++ : fail++;
	wrong++;
	(isLeapYear(55))? count++ : fail++;
	wrong++;
	//16 tests
	if(wrong == fail){
		cout << "All tests passed, " << count + fail << " tests ran" << endl;
	}


}

//main method; some variables; and output for years before and after BCE
int main(){
	string signal;
	string month;
	int year;
	int numDays;
	int routine = 0;
	cout << "Enter any value to start program (press q to quit): " << endl;

	cin >> signal;
	while(signal != "q" && signal != "Q"){
		routine = 1;
		start(year, numDays, month);
		if(routine = 1){
			cout << "Based on the information the number of days in " << month << " in the year ";
			if(year < 0){
				cout << abs(year) << " B.C.E";
			}else{
				cout << year << " C.E.";
			}

			cout << " is " << numDays << endl;

		}
		cout << "Enter any value to start (press q to quit): " << endl;
		cin >> signal;
	       	routine = 0;	
	}

	//These test the functions that don't require user input
	//Commented out; uncomment to run
	//TestingLeapYear();
	//AutomatedTestingMonth();
	return 0;

}

