#include <iostream>

using namespace std;

int main(){
	
	//Variables for price of software, also set constants for discounts
	const int softPrice = 99;
	const double tens = 0.20;
	const double twen2four = 0.30;
	const double fif2nine = 0.40;
	const double overHund = 0.50;

	//Variables set for number of units sold and total cost
	int units;
	double cost = 0.0;

	cout << "How many units were purchased?" << endl;

	cin >> units;

	//I added 0 with negative input, as it makes no sense to purchase 0 items
	///Check to make sure there are positive number of items sold.
	if (units < 1){
		cout << "Invalid number. End of program." << endl;
		return -1;
	
	}

	//Here we determine the cost of the items before discount
	cost = (units * softPrice);
	
	// This the conditional block that checks for ranges
	if(units >= 10 && units <= 19){
		cost -= (cost * tens);
	}else if(units >= 20 && units <= 49){
		cost -= (cost * twen2four);
	}else if(units >= 50 && units <= 99){
		cost -= (cost * fif2nine);
	}else if(units >= 100){
		cost -= (cost * overHund);
	}

	cout << "The total cost for today is: " << cost << endl;

	return 0;
 

}

