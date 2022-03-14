#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std; 
// Necessary header files to properly run program


//For this project I used global variables becaause of all the functions
int days = 0;
double dailyRate = 0.0;
double medCharges = 0.0;
double variousCharges = 0.0;
string stayType;
int stayTypeInt = 0; 

//inpatient function, this actually handles both functions
//returns the value
double hospitalCharges(int days, double dailyRate, double medCharges, double variousCharges){
	double val = 0.0;
	val = (days * dailyRate) + medCharges + variousCharges;
	return val;
}
//outpatient function, this function basically does nothing, calls the other function with preset values
//returns the value.
double hospitalCharges(double medCharges , double variousCharges){
	double val = 0.0;
	val = hospitalCharges(0,0,medCharges, variousCharges);
	return val; 
}

// This is a big function, that ensures inpatient/outpatient is written,
// removes all white space and sends the values to lowercase to maake it easier.
// returns 1 if ture, 0 if false
int validateInput(string s){
	int ret = 0;
	cout << "Enter \"inpatient\" for inpatient care. " <<
	"Or enter \"outpatient\" for outpatient care. " << endl;
	cin >> s;
	while(!cin){
		string ex;
		cin.clear();
		cin >> ex;
		cout << "Enter \"inpatient\" for inpatient care. " <<
			"Or enter \"outpatient\" for outpatient care. " << endl;
		cin >> s;
	}
	s.erase(remove(s.begin(),s.end(), ' '), s.end());
	while(ret < s.length()){
		s[ret] = tolower(s[ret]);
		ret++;
	}
	ret = (s == "inpatient" || s == "outpatient") ? 1 : 0;
	if(s == "inpatient"){
		stayTypeInt = 0;
	}else if(s == "outpatient"){
		stayTypeInt = 1;
	}
	return ret; 
}

//funky function that outputs the correct prompt for the user
//recursive call into the function if given the wrong input
void displayHelper(int i){
	int v = 0;
	switch(i){
		case 1://number of days
			v = 1;
			cout << "Please enter the number of days the patient stayed: " << endl;
			cin >> days;
			break;
		case 2://daily rate
			v = 2;
			cout << "Please enter the daily rate to the nearest cent: " << endl;	
			cin >> dailyRate;
			break;
		case 3: //medication charges
			v = 3;
			cout << "Please enter all medication charges to the nearest cent: " << endl;
			cin >> medCharges;
			break;
		case 4:// hospital services
			v = 4;
			cout << "Please enter all other hospital services to the nearest cent: " << endl;
			cin >> variousCharges;
			break;
	}
	if(!cin){
		string s;
		cin.clear();
		cin >> s;
		displayHelper(v);
	}
}

//used to prompy for output iterates to grab the right prompt, no return needed
void display(int inOrOut){
	int c = 0;
	//0 is inpatient
	if(inOrOut == 0){
		while(c < 4){
			displayHelper(c+1);
			c++;
		}
	}// 1 is outpatient
	else{
		while(c < 2){
			displayHelper(c+3);
			c++;
		}
	}


}

//Compressed main function, as most functionality was handled elsewhere
int main(){
	double totalCharges = 0.0;
	int i = 2;
	int valid = 0;

	//main control, kicks out once we decrease i
	while(i > 1){
		cout << "Let's calculate the price of the stay. "<< endl;
		//won't stop until we know what's input is one of two words.
		while(valid != 1)
		{
			valid = validateInput(stayType);
		}
		//easy way to handle control, 
		switch(stayTypeInt){
			//inpatient is 0;
			case 0:
				display(0);
				totalCharges = hospitalCharges(days, dailyRate, medCharges, variousCharges);
				break;
			//outpatient is 1;
			case 1:
				display(1);
				totalCharges = hospitalCharges(medCharges, variousCharges);
				break;
		}
		//output the info, Could be ssent to an outstreamm, but this works as well.
		cout << fixed << setprecision(2) << "The total charges for the " << stayType << " stay were: " << totalCharges << endl;
		i--;
	}
	
	return 0;
}
