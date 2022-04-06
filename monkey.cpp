#include <iostream>
#include <string>
#include <array>
#include <iomanip>
using namespace std;

//Constants to represent table for monkeys and days
const int MONKEY = 3;
const int DAYS = 5;

//Function that calculates the least amount of food eaten
//for a specific monkey throughout the week and calculates total
void least(array<array<double,DAYS>,MONKEY>& a){
	double least = 0.0;
	double current = 0.0;
	int which = 0, i = 0, j = 0;
	for(i = 0; i < MONKEY; i++){
		for(j = 0; j < DAYS; j++){
			current += a[i][j];
		}
		if(least == 0){
			least = current;
		}else if(current < least){
			least = current;
			which = i;
		}
		current = 0;
	}

	cout << "Over the week the least amount of food was eaten by monkey ";
	cout << (which+1) << " at a weight of " << least << " lbs."; 
	cout << ", we offset by 1 because monkey zero, may not be clear." << endl;

}

//Function that calculates the greatest amount of food eaten for a specific
//monkey throughout the week and calculates total
void greatest(array<array<double,DAYS>,MONKEY>& a){
	double greatest = 0.0;
	double current = 0.0;
	int which = 0, i = 0, j = 0;
	for(i = 0; i < MONKEY; i++){
		for(j = 0; j < DAYS; j++){
			current += a[i][j];
		}
		if(greatest == 0){
			greatest = current;
		}else if(current > greatest){
			greatest = current;
			which = i;
		}
		current = 0;
	}

	cout << "Over the week the greatest amount of food was eaten by monkey ";
	cout << (which+1) << " at a weight of " << greatest << " lbs.";
	cout << ", we offset by 1 because monkey zero, may not be clear." << endl;
}


//Function that returns the average per day for each monkey
array<double,DAYS> average(array<array<double,DAYS>,MONKEY>& a, array<double,DAYS>& d){
	double sum = 0.0;
	int i = 0, j = 0;
	for(i = 0; i < MONKEY; i++){
		for(j = 0; j < DAYS; j++){
			d[j] += a[i][j];
		}
	}
	for(i = 0; i < DAYS; i++)
		d[i] = d[i] / 3.0;
	return d;
}


//Function displays average per day
void AveragePerDay(array<double,DAYS>& d){
	int i = 0;
	while(i < DAYS){
		cout << "The average amount of food for "; 
		switch(i){
		case 0:
			cout << "Monday is ";
			break;
		case 1:
			cout << "Tuesday is ";
			break;
		case 2:
			cout << "Wednesday is ";
			break;
		case 3:
			cout << "Thursday is ";
			break;
		case 4:
			cout << "Friday is ";
			break;
		}
		cout << fixed << setprecision(2) << d.at(i) << " lbs." << endl;
	i++;
	}
}

//Function that allows data to be placed into 2-D array
//One issue; doesn't allow values of zero, but doesn't let you know you'll
//need to add a PROPER value; just acts like the value isn't entered
void addData(array<array<double,DAYS>,MONKEY>&a){
	cout << "We need you input data for feeding amounts of monkeys." << endl;
	int i = 0, j = 0; 
	double val = 0.0;
	for(i = 0; i < MONKEY; i++){
		for(j = 0; j < DAYS; j++){
			cout << "Enter weight in pounds: " << endl;
			cin >> val;
			while(!cin){
				string ex;
				cin.clear();
				cin >> ex;
				cout << "Error, enter weight in pounds: " << endl;
				cin >> val;
			}
			if(val <= 0){
				j = j - 1;
			}else{
				a[i][j] = val;
			}
		}
	}

}

//Nothing but function calls to display data and input data;
int main(){

	array<double,DAYS> ave{};
	array<array<double, DAYS>, MONKEY> table{};
	addData(table);
	ave = average(table,ave);
	AveragePerDay(ave);
	least(table);
	greatest(table);

	return 0;
}
