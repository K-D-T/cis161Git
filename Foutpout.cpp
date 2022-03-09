#include <math.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;
//Necessary include statements to ensure functional program

int main(){
		
	//Various variables, used to capture info and output responses
	double principal;
	double interestRate; 
	int compound;
	double savings;
	ostringstream vOSS;
	string path;

	cout << "We're going to show possible savings, press any key to continue (enter q to quit)" << endl;
	cin >> path;
	
	//Control of the program, if q is enter, program quits
	while(path != "q"){
		cout << "Enter principal: ";
	       	cin >> principal;
		//Blocks invalud input for variable principal
		while(!cin){
			string s;
			cin.clear();
			cin >> s;
			cout << "Enter principal: ";
			cin >> principal;
		}	
		cout << "Enter interest rate (as percent): ";
	     	cin >> interestRate;
		//Blocks invalid input for variable interest rate
		while(!cin){
			string s;
			cin.clear();
			cin >> s;
			cout << "Enter interest rate (as percent): ";
			cin >> interestRate;
		}	
		cout << "Enter number of times compounded: ";
		cin >> compound;
		//Blocks invalid input for compound
		while(!cin){
			string s;
			cin.clear();
			cin >> s;
			cout << "Enter number of times compounded: ";
			cin >> compound;
		}
	//clear input, output newline
	cin.clear();
	cout << endl;

	//Set Output strean for 2 decimals place, create "table" in output with enough space
	vOSS << fixed << setprecision(2);
	vOSS << setw(20) << left << "Interest rate:" << setw(14) << right << interestRate << "%" << endl;
        vOSS << setw(20) << left << "Times Compounded:" << setw(15) << right << compound << endl;
	vOSS << setw(20) << left << "Principal:         $" << setw(15) << right << principal << endl;
	vOSS << setw(20) << left << "Amount in Savings: $" << setw(15) << right << principal * pow((1+((interestRate/100)/compound)),compound);	
	cout << vOSS.str() << endl;
	vOSS.str("");
	vOSS.clear();

	//Reset all variables to run program again if needed
	compound = 0;
	interestRate = 0;
	principal = 0;
	savings = 0;
	cout << "Press any key to continue, (enter q to quit)" << endl;
	cin >> path;
	}
	return 0;
	
}
