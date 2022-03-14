#include <iostream>

using namespace std;

//Function used to determine average of four values passed into the function
double averageFourTemperatures(int a, int b, int c, int d){
	double average = (a + b + c + d) / 4.0;
	return average; 
}


//Function used to validate info sent by user
int validateInfo(){
	int val = 0;
        cin >> val;	
	while(!cin){
		string s;
		cin.clear();
		cin >> s;
		cout << "Pleaase enter a valid integer: " << endl;
		cin >> val;
	}
	return val;
}

int main(){

	//Variables used to capture parameters passed through
	int first; int second;
	int third; int fourth;
	int i = 0;
	
	cout << "Let's find the average of four numbers." << endl;
	//easy way to ensure values are passed through, and output proper statement to user
	while(i <= 4){
		switch(i){
			case 1:
				cout << "Enter the first integer: " << endl;
				first = validateInfo();
				break;
			case 2:
				cout << "Enter the second integer: " << endl;
				second = validateInfo();
				break;
			case 3:
				cout << "Enter the third integer: " << endl;
				third = validateInfo();
				break;
			case 4:
				cout << "Enter the fourth integer: " << endl;
				fourth = validateInfo();
				break;
		}
		i++;
	}
	//Return statement used to output value
	cout << "The average of the four numbers entered is: " << 
		averageFourTemperatures(first, second, third, fourth) << endl;


	return 0;
}
