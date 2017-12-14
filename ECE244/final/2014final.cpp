#include <iostream>
#include <cstdlib>
using namespace std;

class Name {
private:
	string* firstName; string* lastName;
public:
	Name(string fname, string lname); Name(const Name & src);
	~Name();
	void print() const;
	Name* operator=(Name& rhs);
};

Name::Name(string fname, string lname) { firstName = new string(fname);
	lastName = new string(lname);
}
Name::Name(const Name & src) {
	firstName = new string(*(src.firstName)); lastName = new string(*(src.lastName));
}
Name::~Name() {
	delete firstName; delete lastName;
}
void Name::print() const {
	// This prints the first name, followed by a space, followed // by the last name
	cout << *firstName << " " << *lastName << endl;
}
//add overloadint = assing
Name* Name::operator=(Name& rhs){
	firstName = new string(*(rhs.firstName));
	lastName = new string(*(rhs.lastName));
}


void Q2(){
	string Tom = "Tom";
	string Johns = "Johns"; string Michael = "Michael"; 
	string Jackson = "Jackson"; string Sarah = "Sarah"; string Johnson = "Johnson";
	Name first(Tom, Johns);
	Name second(Michael, Jackson); Name third(Sarah, Johnson);
	first.print(); second.print(); third.print();
	first = second; second = third; third = first;
	first.print(); second.print(); third.print();
// Point A return (0);
	return;
}
class Node {
private:
	int* value;
	Node* next;
public:
	Node(int a) { value = new int; *value = a; next = NULL;}
	void setvalue(int a){ *value = a; } 
	int getValue(){ return *value; } 
	void setNext(Node* n){ next = n; }
	Node* getNext(){ return next; } 
	void print(){
		//cout << 1 << endl;
		cout << *value << endl;
		if(next != NULL) next->print();
	}
};

void Q3(){
	int i = 0; 
	Node* p;
	Node t1(i ) ;
	p = &t1; 
	i++;
	// for ( ; i < 100; i++) { 
		Node t2(i);
		p->setNext(&t2); 
		p = &t2;
	// }
	// Point A 
	cout << t1.getNext()->getNext() << endl;
	return;

}

class SmartTarray { 
private:
	int **array;
	int size;
public:
	SmartTarray( int arraySize ){
		array = new int*[arraySize];
		for(int i = 0; i < arraySize; i++){
			array[i] = new int(i);
		}
		size = arraySize;
	}
	void print(){
		for(int i = 0; i < size; i++){
			cout << *(array[i]) << endl;
		}
	}
	int* operator[](int index){
		if(index >= size) return NULL;
		return array[index];
	}

};


void Q4(){
	SmartTarray array(5);
	array.print();
	cout << array[3] << endl;
}


int main(int argc, char const *argv[]){
	Q4();


	return 0;
}