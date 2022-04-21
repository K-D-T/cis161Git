#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Class that handles person attributes, because class will be derived
//from this we can avoid reqriting functions;
class Person{
	private:
		string fName;
		string lName;
	public:
		Person(){fName = "first name"; lName = "last name";}
		Person(string first, string last){fName = first,lName = last;}
		string getFirst(){
			return fName;
		}
		string getLast(){
			return lName;
		}
		void setFirst(string first);
		void setLast(string last);
};
//Allows you to set first name; info popps up with empty string
void Person::setFirst(string first){
	if(first == "")
		cout << "Please provide a name." << endl;
	else
		fName = first;
}
//alllows you to set last name; info pops up with empty string
void Person::setLast(string last){
	if(last == "")
		cout << "Please provide a name." << endl;
	else
		lName = last;
}
//Class and majority of functionality 
class Student : public Person{
	private:
		int student_id;
	public:
		Student(){student_id = 0;}
		Student(int s_id){student_id = s_id;}
		int getSID(){
			return student_id;
		}
		void setSID(int s);
};

//Function for the class student to set the student id, minor error checking
void Student::setSID(int s){
	if(s < 0){
		student_id = 0;
		cout << "Error student id must be positive value." << endl;
	}
	else
		student_id = s;
}


//Main method to test out the derived class
int main(){

	Student s;
	cout << s.getFirst() << " " << s.getLast() << endl;
	cout << s.getSID() << endl;
	s.setFirst("Kenyon");
	s.setLast("Thomas");
	s.setSID(2304);
	cout << s.getFirst() << " " << s.getLast() << endl;
	cout << s.getSID() << endl;
	s.setSID(-203);
	cout << s.getFirst() << " " << s.getLast() << endl;
	cout << s.getSID() << endl;
	s.setSID(5403);
	cout << s.getFirst() << " " << s.getLast() << endl;
	cout << s.getSID() << endl;
	return 0;
}

