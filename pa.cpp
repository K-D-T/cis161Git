#include <iostream>
using namespace std;

int main(){
	float price1;
	float price2;

	cout << "Enter id 1: ";
	cin >> price1;
	cout << "Enter id 2: ";
	cin >> price2;

	float* pricePtr;

	//The only line necessary if I understood the point of this assignment
	(price1 > price2) ? pricePtr = &price1 : pricePtr = &price2;

	if(pricePtr == nullptr){
		cout << "The prices are the same." << endl;
	}else{
		cout << "The largest price is " << *pricePtr << "." << endl;
	}
}

