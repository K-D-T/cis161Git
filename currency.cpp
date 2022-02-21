#include <iostream>
//Line used to access the input/output
#include <iomanip>
// Use this to activate precision to truncate floats/doubles
using namespace std;
// allows for easier access to std name 

//main method used to run program
int main(){
	
	//reusable variable used to show how much of a specific currency is available
	double currencyAmount;
	//represents the value in USD of total currency
	double total = 0.0;

	//Value represents conversion rate of yen
	const double cYen = 0.16;
	//Value represents conversion rate of euros
	const double eEuros = 1.14;
	//Value represents conversion rate of pesos
	const double mPesos = 0.049;

	//First line finding out how many euros we have and placing value into currency
	cout << "How many Euros do you have?" << endl;
	cin >> currencyAmount;

	//converting euros to USD value and adding to total
	total += (currencyAmount * eEuros);

	//Finding out how many pesos we have and placing value into currency, overriding initial value
	cout << "How many Mexican Pesos do you have?" << endl;
	cin >> currencyAmount;

	//converting pesos to USD value and adding to total
	total += (currencyAmount * mPesos);

	//finding out how many yen we have and place value into currency, overriding initial value
	cout << "How many Chinese Yen do you have?" << endl;
	cin >> currencyAmount;

	//converting yen to USD value and adding to total
	total += (currencyAmount * cYen);

	//output the value, fixed and set precision allow us to truncate the end of the value.
	cout << fixed << setprecision(2) << "The total value in US dollars is: " << total << endl;

	//return statement to close out the program
	return 0;
}
