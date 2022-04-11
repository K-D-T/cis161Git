#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
//necessary preprocessor

//enum to represent day of week
enum DayOfWeek {SUNDAY,MONDAY,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY,SATURDAY};
//struct to repsent date 
struct Date{
	DayOfWeek dayOfWeek;
	int dayOfMonth;
	int month;
	int year;
};

//leap year function
bool isLeapYear(int year){
	if(year % 4 != 0){
		return false;
	}else if(year % 4 == 0 && year % 100 == 0 && year % 400 != 0 ){
		return false;
	}
	return true;
}
//first part to represent a date 0-6;
void userInput(int& i){
	cout <<  "Enter a day number to represent day, Sunday is 0, Monday is 1, and so forth." << endl;
	cin >> i;
	while(!cin){
		cout << "Error found, enter a number between 0 and 6." << endl;
		string s;
		cin.clear();
		cin >> s;
		cin >> i;
	}
	if(i < 0 || i > 6)
		userInput(i);
}

//This only allows numbers, negatives are okay to represent BCE
int validateYearInput(int& i, Date& d){
	int val = 0; 
	cout << "Enter a year, negative can represent B.C. or B.C.E. : " << endl;
	cin >> val;
	while(!cin){
		string s;
		cin.clear();
		cin >> s;
		cout << "Enter a year, negative can represent B.C. or B.C.E. : " << endl;						cin >> val;
	}
	d.year = val;
	return val;
}

//Checks for month; 1-12 Jan- Dece; sets month in Date object;
void validateMonth(int& i, Date& d){
	cout << "Enter a number to represent a month, 1 is January... up to 12 which is December." << endl;
	cin >> i;
	while(!cin){
		string s;
		cin.clear();
		cin >> s;
		cout << "Enter a number between 1 and 12, inclusive to represent a month." << endl;
		cin >> i;
	}
	if(i < 1 || i > 12)
		validateMonth(i, d);
	d.month = i;
}
// use with validate day to ensure right day has been given
bool dayMonth(int date, int month){
	switch(month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(date > 0 && date <=31){
				return true;
			}else{
				return false;
			}
			break;
		case 6:
		case 9:
		case 11:
			if(date > 0 && date <= 30){
				return true;
			}else
				return false;
			break;
		case 2:
			if(date > 0 && date <= 29){
				return true;
			}else{
				return false;
			}
		default:
			cout << "Error present";
			return false;

	}
	return false;

}

//Checks for a date; also checks for feburary edge cases 
void validateDay(Date& d){
	int date = 0;
	cout << "Now let's enter a date, remember there are restrictions on certain months." << endl; 
	cin >> date;
	while(!cin){
		string s;
		cin.clear();
		cin >> s;
		cout << "Error present, Enter a date" << endl;
		cin >> date;
	}
	if(date < 0 || date > 31){
		validateDay(d);
	
	}else if(!isLeapYear(d.year) && d.month == 2 && date > 28){
		cout << "Error present." << endl;
		validateDay(d);
	}
		
	else if(!dayMonth(date, d.month) || 
			(d.month == 2 && d.dayOfMonth == 29 && !isLeapYear(d.year))){
		cout << "Error present." << endl;
		validateDay(d);
	}else{
		d.dayOfMonth = date;
	}
}
// use the enum to set to specific day string 
string setDate(Date& d){
	DayOfWeek v = d.dayOfWeek;
	string s;
	switch(v){
		case SUNDAY:
			s = "Sunday";
			break;
		case MONDAY:
			s = "Monday";
			break;
		case TUESDAY:
			s = "Tuesday";
			break;
		case WEDNESDAY:
			s = "Wednesday";
			break;
		case THURSDAY:
			s = "Thursday";
			break;
		case FRIDAY:
			s = "Friday";
			break;
		case SATURDAY:
			s = "Saturday";
			break;
		default:
			cout << "Error present, fix issue" << endl;
			return NULL;

	}
	return s;
}
// unnecessary output function
void out(Date& d, ostringstream& o){
	o << d.month << "/" << d.dayOfMonth << "/" << d.year;
}
//main function controls output
int main(){
	
	//Variables to set up
	Date date; 
	DayOfWeek day;
	ostringstream oSS;
	string output;
	int dayNumber = -1;

	//Function calls
	userInput(dayNumber);
	day = static_cast<DayOfWeek>(dayNumber);
	date.dayOfWeek = day;
	output = setDate(date);

	oSS << output << ", ";
	
	//more function calls to finish program
	dayNumber = validateYearInput(dayNumber,date);
	date.year = abs(dayNumber);
	validateMonth(dayNumber,date);
	validateDay(date);

	//output the string to show date
	out(date,oSS);
	output = oSS.str();
	cout << output << endl;
	return 0;
}
