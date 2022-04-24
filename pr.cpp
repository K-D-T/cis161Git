#include <iostream>
#include <string>
using namespace std;

//function that takes referenced variables and assigns values
void fullName(string& first, string& last){

	cout << "Let's display a name" << endl;
	cout << "What's the first name: ";
	cin >> first;
	cout << "What's the last name: ";
	cin >> last;
}

// Holds output referenced variables
int main(){

	string f;
	string l;

	fullName(f,l);

	cout << "The full name entered is " << f << " " << l << endl;
	return 0;
}
