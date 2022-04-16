#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Student{
	private:
		string fName;
		string lName;
		double grade;
	public:
		Student(string first, string last, double grade_){fName = first; lName = last; grade = grade_;}
		Student(){fName = "first name", lName = "last name", grade = 0.0;}
		string getFirst(){
			return fName;
		}
		string getLast(){
			return lName;
		}
		double getGrade(){
			return grade;
		}
		void setFirst(string first);
		void setLast(string last);
		void setGrade(double grade);
};

void Student::setLast(string last){
	if(last == ""){
		cout << "Please provide a name." << endl;
	}else{
		lName = last;
	}	
}

void Student::setFirst(string first){
	if(first == ""){
		cout << "Please provide a name." << endl;
	}else{
		fName = first;
	}
}

void Student::setGrade(double grade_){
	if(grade_ < 0){
		cout << "You need to enter a value greater than 0." << endl;
	}else{
		grade = grade_;
	}
}

void userInput(vector<Student>& c, Student s){
	string sentinel;
	string f;
	string l;
	double g; 
	while(sentinel != "q" && sentinel != "Q"){
		cout << "Enter a first name:" << endl;
		cin >> f;
		while(!cin){
			string v;
			cin.clear();
			cin >> v;
			cout << "Enter a first name:" << endl;
			cin >> f;
		}
		cout << "Enter a last name:" << endl;
		cin >> l;
		while(!cin){
			string v;
			cin.clear();
			cin >> v;
			cout << "Enter a last name:" << endl;
			cin >> l;
		}
		cout << "Enter a grade as a double:" << endl;
		cin >> g;
		while(!cin){
			string v;
			cin.clear();
			cin >> v;
			cout << "Enter a grade:" << endl;
			cin >> g;		
		}
	
		s.setFirst(f);
		s.setLast(l);
		s.setGrade(g);
		c.push_back(s);
		f = "";
	       	l = "";
		g = 0.0;

		cout << "Press any key to continue, press q(Q) to quit." << endl;
		cin >> sentinel;
	}

}

void print(vector<Student>& v){
	for(auto & it : v){
	 	cout << fixed << setprecision(2) << it.getFirst() << " " << it.getLast() << ",  Grade: " << it.getGrade() << endl;   
	}
}

int main(){
	vector<Student> currentStudents;
	Student s; 
	userInput(currentStudents, s);
	print(currentStudents);

	return 0;
}
