#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <sstream>

using namespace std;

//check eof first
bool fewOrInvalid(bool eof, bool fail, stringstream &lineStream){
	if(eof == true){
		cout << "Error: too few argument" << endl; 
		lineStream.clear();
		return true;
	}
	else if(fail == true){
		cout << "Error: invalid argument" << endl;
		lineStream.clear();
		lineStream.ignore(1000, '\n');
		return true;
	}
}


int parser() {
	string line, command;
	//char temp;
    //for detecting more argument
	bool errorForInput = false;
	
	// Get a line from standard input
	getline (cin, line); 
	while ( !cin.eof () ) {
		// Put the line in a stringstream for parsing
		// Making a new stringstream for each line so flags etc. are in a known state
		stringstream lineStream (line);
		lineStream >> command;
		

		//insert resista
		if (command == "insertR") {
			string name;
			double resistance;
			int node1, node2;


			//ok now load one by one for checking "too few argument and invalid argument"
			lineStream >> name >> resistance >> node1;
			errorForInput = fewOrInvalid(lineStream.eof(), lineStream.fail(), lineStream);
			lineStream >> node2;
			if(errorForInput == false){
				errorForInput = fewOrInvalid(false, lineStream.fail(), lineStream);	
			}
			//checking too much argument
			if(errorForInput == false && lineStream.eof() != true){
				errorForInput = true;
				cout << "Error: too many arguments"  << endl;
			}
			
			//do nothing
			if(errorForInput == true){
				
			}
			//error same node
			else if(node1 == node2) {
				cout << "Error: both terminals of resistor connect to node " << node2 << endl;
			}
			//node outof range
			else if(node2 > 5000 || node2 < 0){
				cout << "Error: node " << node2 << " is out of permitted range 0-5000" << endl;
			}
			else if(node1 > 5000 || node1 < 0){
				cout << "Error: node " << node1 << " is out of permitted range 0-5000" << endl;
			}
			//negative resistance
			else if(resistance <= 0) {
				cout << "Error: negative resistance" << endl;
			}
			//name is "all"
			else if(name == "all"){
				cout << "Error: resistor name cannot be the keyword all" << endl;
			}
			else{
				cout << "Inserted: resistor " << name << " " << resistance << " Ohms " << node1 
					 << " -> " << node2 << endl;
			}
		}

		//change the value
		else if (command == "modifyR") {
			string name;
			double resistance;
			lineStream >> name;
			errorForInput = fewOrInvalid(lineStream.eof(), false, lineStream);
			if(errorForInput == false){
				lineStream >> resistance;
				errorForInput = fewOrInvalid(false, lineStream.fail(), lineStream);
			}
			//checking too much argument
			if(errorForInput == false && lineStream.eof() != true){
				errorForInput = true;
				cout << "Error: too many arguments"  << endl;
			}
		
			//do nothing
			if(errorForInput == true){
				
			}
			else if(resistance < 0){
				cout << "Error: negative resistance" << endl;
			}
			else if(name == "all"){
				cout << "Error: resistor name cannot be the keyword all" << endl;
			}
			else{
				cout << "Modified: resistor " << name << " to " << resistance << " Ohms" << endl;
			}
		}
		//print resistor
		else if (command == "printR") {
			string name;
			errorForInput = fewOrInvalid(lineStream.eof(), false, lineStream);
			lineStream >> name;

			//checking too much argument
			if(errorForInput == false && lineStream.eof() != true){
				errorForInput = true;
				cout << "Error: too many arguments"  << endl;
			}

			if(errorForInput == true);
			else if(name == "all") cout << "Print: all resistors" << endl;
			else cout << "Print: resistor " << name << endl;
		}
		//print nodes
		else if (command == "printNode"){
			string node;
			errorForInput = fewOrInvalid(lineStream.eof(), false, lineStream);
			lineStream >> node;

			//checking too much argument
			if(errorForInput == false && lineStream.eof() != true){
				errorForInput = true;
				cout << "Error: too many arguments"  << endl;
			}

			if(errorForInput == true);
			else if(node.compare("5000") > 0 || node.compare("0") < 0) {
				cout << "Error: node " << node << " is out of permitted range 0-5000" << endl;
			}
			//node cannot be letter
			else if(isdigit(node[0]) != true){
				cout << "Error: invalid argument" << endl;
				errorForInput == true;
			}
			else if(node == "all") cout << "Print: all nodes" << endl;
			else cout << "Print: node " << node << endl;
		}
		//detect resistor
		else if (command == "deleteR"){
			string name;
			errorForInput = fewOrInvalid(lineStream.eof(), false, lineStream);
			lineStream >> name;
			
			//checking too much argument
			if(errorForInput == false && lineStream.eof() != true){
				errorForInput = true;
				cout << "Error: too many arguments"  << endl;
			}
			
			if(errorForInput == true);
			else if(name == "all") cout << "Deleted: all resistors" << endl;
			else cout << "Deleted: resistor " << name << endl;
		}
		//other would be error
		else{
			cout << "Error: invalid command" << endl;
		}

		//new input here
		getline (cin, line);
	} // End input loop until EOF.
	return 0;
}

int main(int argc, char const *argv[])
{
	parser();

	return 0;
}

