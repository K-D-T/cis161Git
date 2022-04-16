#include <iostream>
#include <string>

using namespace std;
//
//Class for product with getter and setter methods.
class Product{
	private:
		string name;
	public:
		Product(){name = "";}
		Product(string name1) {name = name1;}
		string getName(){
			return name;
		}
		void setName(string name1);
};
//set the name for any product
void Product::setName(string name1){
	name = name1;
}

//Class with constructor; private and public methods
class Factory{
	private:
		string location;
		int capacity;
	public:
		Factory(){location = ""; capacity = 1;}
		Factory(string location1, int capacity1){location = location1; capacity = capacity1;}
		void makeProduct(Product product);
		void increaseCapacity();
		void decreaseCapacity();
		void setLocation(string location1);
		void setCapacity(int value);
};
//set capacity to any factory
void Factory::setCapacity(int value){
	capacity = value;
}
//increase the capacity by one
void Factory::increaseCapacity(){
	capacity++;
}
//decrease the capacity by one
void Factory::decreaseCapacity(){
	capacity--;
}
//change the location of the factory if neccessary
void Factory::setLocation(string location1){
	location = location1;
}
//create a product to be made at the factory
void Factory::makeProduct(Product product){
	if(capacity > 0){
		cout << "Factory is now making " << product.getName() << endl;
	}else{
		cout << "Factory out of capacity." << endl;
	}
}


// function command
int main(){
	Factory f1;
	f1.setLocation("Des Moines");
	f1.setCapacity(27);

	Factory f2;
	f2.setLocation("Davenport");
	f2.setCapacity(30);

	Product p1;
	p1.setName("Thinga");

	Product p2;
	p2.setName("Ma");

	Product p3;
	p3.setName("Jig");
	
	Product p4;
	p4.setName("Su");

	Product p5;
	p5.setName("ZQ");
		
	f1.makeProduct(p1);
	f1.makeProduct(p2);
	f1.makeProduct(p3);

	f2.makeProduct(p4);
	f2.makeProduct(p5);


	return 0;
}


