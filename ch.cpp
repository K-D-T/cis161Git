#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Base class of ship, accessors and mutators present
class Ship{
	private:
		string name;
		string year;
		
	public:
		Ship(){name = "",year = "";}
		Ship(string n, string y){name = n; year = y;}
		string getName(){
			return name;
		}
		string getYear(){
			return year;
		}
		
		void setYear(string y);
		void setName(string n);
		virtual void print(){
			cout << "The name of the ship is " << getName();
			cout << " and it was built in the year " << getYear() << endl; 
		}


};

//Derived clases for cruise ship, accessors and mutators present
class CruiseShip : public Ship{
	private:
		int maxPass;
	public:
		CruiseShip(){maxPass = 1;}
		CruiseShip(int m){maxPass = m;}
		int getMaxPass(){
			return maxPass;
		}
		void setMaxPass(int m);
		void print(){
			cout << "The name of the ship is " << getName();
			cout << " and the maximum number of passengers is " << getMaxPass() << endl;
		}
};
// Dervired class for cargo ship, accessors and mutators present
class CargoShip : public Ship{
	private:
		int cargoCapacity;
	public:
		CargoShip(){cargoCapacity = 1;}
		CargoShip(int c){cargoCapacity = c;}
		int getCargoCap(){
			return cargoCapacity;
		}
		void setCargoCap(int c);
		void print(){
			cout << "The name of the ship is " << getName();
			cout << " and the capacity of cargo is " << getCargoCap() << " tons." << endl;
		}

};
//mutator to set the capacity of the cargo
void CargoShip::setCargoCap(int c){
	if(c < 1){
		cout << "There needs to be a higher number to represent cargo capacity." << endl;
		cargoCapacity = 1;
	}
	else
		cargoCapacity = c;
}
//mutator to set the numnber of passengers
void CruiseShip::setMaxPass(int m){
	if(m < 1){
		cout << "There needs to be a higher number to represent passengers." << endl;
		maxPass = 1;
	}
	else
		maxPass = m;
}
//Mutator to set year , no error checking to ensure number present
void Ship::setYear(string y){
	if(y == ""){
		cout << "A year must be present." << endl;
		y = "0";
	}
	else 
		year = y;
}
//Mutator for ship name
void Ship::setName(string n){
	if(n == ""){
		cout << "A name must be present." << endl;
		n = "blank";
	}
	else
		name  = n;
}

//Easy output function to display proper print function 
void output(vector<Ship*>& v){
	for(auto & it : v)
		it->print();
}

int main(){

	vector<Ship*> v;
	
	Ship s;
	CruiseShip c;
	CargoShip cs;
	//s = new Ship();	
	//s->setName("S.S. Minnow Johnson");
	//s->setYear("1997");
	
	c.setName("Titano");
	c.setMaxPass(2000);
	
	cs.setName("Roxxon");
	cs.setCargoCap(20332010);
	Ship *pc = &c;
	Ship *ps = &cs;
	
	v.push_back(pc);
	v.push_back(ps);
	
	output(v);

	return 0;
}
