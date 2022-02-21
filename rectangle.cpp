#include <iostream>
//iostream is the input/output used to interact 

using namespace std;
//this helps connect input/output to specific functions (cin/cout)

//main method used to run the program, without it, nothing happens
int main(){

	//variable set up to represent Area of rectangle.
	int area;

	//variable set up to represent width of rectangle.
	int width;

	//variable set up to represent length of rectangle.
	int length;
	
	//Output to make the program human readable
	cout << "What is the floor width?" << endl;
	
	//Grabs the value that the user inputs to represent width
	cin >> width;

	//Output to make the program human readable
	cout << "What is the floor length?" << endl;
	
	//Grabs the value that the user inputs to represent length
	cin >> length;
	
	// area is compute by multiplying the 2 input values, hardcoded for int
	area = (int) width * (int) length;
	
	//output the value for area
	cout << "The area is " << area << "." << endl;

	//close out the program, doesn't need it for this assignments
	return 0;
}
