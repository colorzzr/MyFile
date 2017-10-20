#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;
//---------------------------------------Q1-----------------------------------------------
bool getNextInt(int &x, stringstream &ss){
	do{
		char temp;
		ss >> temp;
		cout << temp << endl;
		if(temp >= '0' && temp <= '9'){
			x = temp - '0';
			return true;
		}
		else continue;
	}while(ss.eof() != true);
	return false;
}
void Q1() {
 	int x ;
 	string temp;
 	getline(cin, temp);
 	stringstream ss (temp);
 	if( getNextInt(x,ss))
 		cout << "The first token is "  << x << endl ;
 	else
 		cout << "Error: first token is not an int" << endl ;
}


//-----------------------------------------Q4------------------------------------------------
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

//AnExampleClass a;
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

//------------------------------------------Q7-----------------------------------------
class Mystery {
private:
	int value;
public:
	Mystery (const Mystery & s){}
	Mystery (const string & s){}
	~Mystery (){}
	int getValue() const{}
	void setValue(int i){}
	bool operator<(const Mystery & rhs){}
};

void Q7(){
	Mystery d("ddd");
	Mystery e("eee");
	Mystery f("fff");
	Mystery j("fff");
	Mystery Y("fff");
	int v;
	string sv, X;
	sv = "jjjjjj";
	//Question start here
	//fail no default constructor
	//Mystery s;
	//good 
 	Mystery a(sv);
 	//good 
 	Mystery W(X); 

 	Mystery c = sv; 
 	//cout << f.getValue(); 
 	(d < e); 
 	Mystery h = j;
 	
 	//good
 	//Y = W;

 	//fail: assign different
 	//but not show warning why?<--------------------------------------------
 	e = sv;
	
	//fail: to load int to class
 	//e < v; 
	
	//fai: access to private member
 	//cout << f.value; 

 	//fail: no member function
 	//f = d + e;
}

//------------------------------------------------Q8-----------------------------------------
class Complex {
private:
 	float real;
 	float imag;
public:
 	Complex(); // Default constructor
 	Complex(float r, float imag); // Second constructor
 	int getReal(); int getImag();
 	void setReal(float r);
 	void setImag(float i);
 	void print();
};

//------------------------------------------Q11------------------------------------------
int compute (int i1) {
 	i1 = i1 + 3;
 	return (i1);
}
int compute (int i1, int& i2) {
 	i1 = i1 + 4;
 	i2 = i1 + i2;
 	return (i1 + i2);
}
int compute2 (const int& i1) {
 	return (i1 + i1);
}
void Q11() {
 	int ival1 = 2;
 	int ival2 = 3;
 	int resVal = compute (ival1, ival2);
 	resVal = resVal + compute (ival2);
 	resVal = resVal + compute2 (ival2);
 	//resVal is 45
 	cout << "resVal is " << resVal << endl;
}

//-------------------------------------Q12--------------------------------------------------
class Number {
 	private:
 	int _number;
 	public:
 	Number ();
 	Number (int v);
 	void increment () const;
 	void copy_and_destroy (const Number & other);
 	void print() const;
};

Number::Number () {
 	_number = 0;
}

Number::Number (int num) {
 	_number = num;
}

// //error: assignment of member ‘Number::_number’ in read-only object
// void Number::increment () const {
//  	_number = _number + 1;
// }

// void Number:: copy_and_destroy (const Number & other) {
//  	_number = other._number;
//  	//assignment of member ‘Number::_number’ in read-only object
//  	other._number = 0;
// }

void Number::print() const {
 	cout << _number << endl;
}

int main(int argc, char const *argv[]){
	Q11();
	return 0;
}