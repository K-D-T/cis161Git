#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main(){
	srand(static_cast<uint>(time(nullptr)));
	int secret = rand() % 10 + 1;
	int guess;

	cout << "Guess a number between 1 and 10." << endl;
	cin >> guess;
	
	//THis also causes an infintie loop, as it doesn't allo
	//w corrections.
	//Added user input to correct inifinite loop.
	while(guess < 0 || guess > 10){
		cout << "That is not a number between 1 and 10, try again." << endl;
		cin >> guess;
	}
	
	///This causes an infinite loop
	//Added another input for user to correct infinite loop
	while(guess != secret){
		if(guess < secret){
			cout << "Too low, try again." << endl;
		}else{
			cout << "Too high, try again." << endl;
		}
		cin >> guess;
	}
	cout << "Correct!" << endl;

	return 0;
}
