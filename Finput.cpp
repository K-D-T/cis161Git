// Various plugins to ensure functionality 
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cctype>

using namespace std;

int main(){

	// Variables for various items, including file opening, instream/outstream
	ostringstream oSS;
	istringstream iSS;
	string name;
	string parse;
       	string placehold;
	double value = 0.0;
	int count = 0;
	int namePresent = 0;
	int decimalPresent = 0;
	int i;
	int  validLine = 0;
	string filename;
	ifstream fs;
	

	cout << "Enter a valid filename to start: " << endl;

	cin >> filename;
	oSS << fixed << setprecision(2);
	// Ensures we have an accurate file name
	while(!cin){
		string s;
		cin.clear();
		cin >> s;
		cout << "Enter a valid filename to start: " << endl;
		cin >> filename;
	}
	fs.open(filename);
	//Ensures we can open file, if not close the program
	if(!fs.is_open()){
		cout << "Could not open " << filename << ". Program exited." << endl;
		return 1;
	}
	//While another line on the file exists
	while(getline(fs,parse)){
		istringstream iSS(parse);
		while(iSS >> placehold){
			//This specific line ensures that we go inside the loop and push info to outsteam
			validLine = 1;
			//First item should be name 
			if(namePresent == 0){
				namePresent = 1;
				name = placehold;
			}
			//If name is present, parse the info to find out if it's an Int or double and convert it 
			else if(namePresent = 1){
				i = 0;
				for(i = 0; i < placehold.length(); i++){
					if(isalpha(placehold.at(i))){
						cout << "Incorrect format. Program exited." << endl;
						return 1;
					}
					else if(placehold.at(i) == '.' && decimalPresent == 1){
						cout << "Incorrect format. Program exited." << endl;
						return 1;
					}
					else if(placehold.at(i) == '.' && decimalPresent == 0){
						decimalPresent = 1;
					}
				}
				//Conversions for doubles and ints, increase count to find average
				if(decimalPresent == 1){
					value += stod(placehold);
					decimalPresent = 0;
				}else if(decimalPresent == 0){
					value += stoi(placehold);
				}
				count++;
			}
		}
		//States that we have entered the inner loop ensuring there's data on the line
		//reset values
		if(validLine == 1){
			iSS.clear();
			oSS << name << ": " << value / count << endl;
			value = 0.0;
			count = 0;
			namePresent = 0;
			name = "";
			validLine = 0;
		}
		//Clear file stream
		fs.clear();	
	}	

	//Close file and outpout outstream
	fs.close();
	cout << oSS.str();
	return 0;
}

