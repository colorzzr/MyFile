#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

class DayOfYear {
private:
 	int day; int month;
 	DayOfYear(const DayOfYear & other);
public:
 	~DayOfYear();
 	DayOfYear(int d, int m);
 	int getDay();
 	int getMonth();
 	void setDay(int d);
 	void setMonth(int m);
 	DayOfYear operator=(DayOfYear src);
 	void print();
};
DayOfYear::~DayOfYear () {/* Nothing to do */}
DayOfYear::DayOfYear (int d, int m) {
 	day = d;
 	month = m;
}
DayOfYear::DayOfYear(const DayOfYear & other) {
 	day = other.day; month = other.month;
}
int DayOfYear::getDay() {return (day);}
int DayOfYear::getMonth() {return (month);}
void DayOfYear::setDay(int d) {day = d;}
void DayOfYear::setMonth(int m) {month = m;}
DayOfYear DayOfYear::operator=(DayOfYear src) { day = src.day;
 	month = src.month;
 	return(*this);
}
void DayOfYear::print() {cout << day << "/" << month << endl;}

void mystery (DayOfYear);

//note here no default constructor so all copy shows error
void Q4(){
	//good
	DayOfYear FirstOfJuly(1,7);
 	//good
 	DayOfYear Christmas(25,12);
 	//fail: no default constructor
 	//DayOfYear temp;

 	//good
 	DayOfYear May11(11,5);
 	//constructor in private member
 	//DayOfYear MothersDay = May11;

 	//good
 	DayOfYear today(1,1);
 	//good
 	DayOfYear Oct22(22,10);
 	//fail copy constructor for src in overloading is a private
 	//today = Oct22;

 	//fail: copy constructor for copy in fucntion is a private
 	//mystery(today);
 //return(0);
}

void mystery(DayOfYear source) {
	DayOfYear* temp = new DayOfYear(0,0);
	temp->setMonth(source.getDay());
	temp->setDay(source.getMonth());
	delete temp;
} 

//------------------------------------Q4-----------------------------------------------
#include <iostream>
using namespace std;
class AnExampleClass {
private:
 	int value;
public:
 	AnExampleClass ();
 	AnExampleClass (int v); ~AnExampleClass ();
};
AnExampleClass::AnExampleClass () {
 	value = 0;
 	cout << "Constructing object with value 0"<< endl;
}
AnExampleClass::AnExampleClass (int v) {
 	value = v;
 	cout << "Constructing object with value " << value << endl;
}
AnExampleClass::~AnExampleClass () {
 	cout << "Destructing object with value " << value << endl;
}

AnExampleClass a;
void mysteryy() {
 	cout << "Entering mystery" << endl;
 	AnExampleClass x(100);
 	AnExampleClass* p;
 	p = new AnExampleClass(5);
 	cout << "Leaving mystery" << endl;
 	return;
}

/*************************************
* Constructing object with value 0	 *
* Staring main 						 *
* Constructing object with value 0	 *
* Constructing object with value 0	 *
* Constructing object with value 0	 *
* Destructing object with value 0	 *
* Destructing object with value 0	 *
* Entering mysteryy 				 *
* Constructing object with value 100 *
* Constructing object with value 5	 *
* Leaving mysteryy 					 *
* Destructing object with value 100	 *
* Leaving main 						 *
* Destructing object with value 0	 *
* Destructing object with value 0	 *
**************************************/
void Q5(){
	cout << "Staring main" << endl;
 	AnExampleClass a;
 	if (true) {
 		AnExampleClass* p;
		p = new AnExampleClass[2];
	delete [] p;
	}
 	mysteryy();
 	cout << "Leaving main" << endl;
}

//---------------------------------------Q6--------------------------------------------------

/********
* 10 20 *
* 20 20 *
* 30 30 *
*-------*
* 10 20 *
* 20 20 *
* 30 20 *
*********/
void Q6(){
	int* p1;
	int* p2;
	p1 = new int;
	p2 = new int;
	*p1 = 10;
	*p2 = 20;
	cout << *p1 << " " << *p2 << endl;
	p1 = p2;
	cout << *p1 << " " << *p2 << endl;
	*p1 = 30;
	cout << *p1 << " " << *p2 << endl;
	
	cout << "-----------------------------------------------------------" << endl;
	
	int* p3;
	int* p4;
	p3 = new int;
	p4 = new int;
	*p3 = 10;
	*p4 = 20;
	cout << *p3 << " " << *p4 << endl;
	*p3 = *p4;
	cout << *p3 << " " << *p4 << endl;
	*p3 = 30;
	cout << *p3 << " " << *p4 << endl;

}

int main(int argc, char const *argv[]){
	Q6();
	return 0;
}