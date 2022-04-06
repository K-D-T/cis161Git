#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;


//Function to find the sum of all even values in vector
double sumEven(vector<double>& v){
	int i = 0;
	double sum = 0.0;
	while(i < v.size()){
		if(i % 2 == 0)
			sum += v.at(i);
		i++;
	}
	return sum;
}

//function to get the average, works to ensure value is calculated even if odd final digit isn't added
double getAve(vector<double>& v, double s){
	double t;
	if(v.size() % 2 == 0)
		t = s / (v.size() / 2);
	if(v.size() % 2 != 0)
		t =  s / ((v.size() / 2) + 1);
	return t;
}

//Creates a vector based on user input
//The one thing that i'm not a fan of is the user input makes it hard to let continous values be entered
//had to break it down to wait for sentinel val
void createVector(vector<double>& v){
	string sentinel;
	double val = 0.0;
	cout << "Let's create the vector by adding values." << endl;
	
	while(sentinel != "q" && sentinel != "Q"){
		cout << "Enter a double for temperature: " << endl;
		cin >> val;

		while(!cin){
			string s;
			cin.clear();
			cin >> s;
			cout << "Enter a double for temperature: " << endl;
			cin >> val;
		}
		v.push_back(val);


		cout << "Press any key to continue, press q to quit." << endl;
		cin >> sentinel;
	}

}


//Fairly simple main method, function calls and output to finish it up.
int main(){
	vector<double> temperatures;
	double pop = 0.0;
	createVector(temperatures);
	pop = sumEven(temperatures);
	pop = getAve(temperatures,pop);
	cout << fixed << setprecision(2) << pop << " is the average temperature of even days." << endl; 
	return 0;
}
