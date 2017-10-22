#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

//----------------------------------------Q1-----------------------------------------------

class Circle {
public:
 	Circle( Circle &c ) ;
 	Circle( int radius ) ;
 	void area( const Circle& c ) ;
 	//fail: destructor has no para
 	//~Circle( int i ) ;
private:
 	int x, nr ;
};

void Q1(){
	//fail: no default constructor
	//Circle c1;
}

//--------------------------------------Q2--------------------------------------------------

int a = 6;
int *b = &a;

int * foo( int **c ) {
 		(**c)++;
 		//f to b
 		*c = b;
 		int *d = new int;
 		*d = 10;
 		/* ******************
 		 * a is 6			*
 		 * b is point to a 	*
 		 * c is point to a  *
 		 * d is 10			*
 		 * e is 8 			*
 		 * f is point to a  *
 		 ********************/
 		// Point #1
 	return d;
}

void Q2(){
	int e = 7;
 	int *f = &e;

 	//f to d
 	f = foo( &f );
 	(*f)++;
 	cout << *f << endl;
 	// Point #2
 	/*********************
 	 * a is 6			 *
 	 * b is point to a   *
 	 * c is point to 11	 *
 	 * d no longer exist *
 	 * e is 7			 *
 	 * f is point to 11  *
 	 *********************/

}

//-------------------------------------------Q5---------------------------------------------
class mT{
private:
	static int created;
public:
	mT();
	~mT();
	void print();
};

int mT::created = 0;

mT::mT(){
	mT::created++;
	cout << mT::created << " created" << endl;
}

mT::~mT(){
	mT::created--;
	cout << mT::created << " remainning" << endl;
}

//mT g[2] ;
//mT h ;

void mT::print(){
	cout << created << endl;
}

void testFunction() {
 	mT t ;
 	mT *p = NULL ;
 	cout << "testFunction" << endl ;
	p = new mT ;
 	cout << "leaving" << endl ;
}	

void Q5(){
	mT m ;
 	mT*p = new mT ;
 	cout << "main" << endl ;
 	testFunction() ;
 	cout << "back" << endl ;
 	delete p ;
 	cout << "exiting" << endl ;
}

//-----------------------------------Q6------------------------------------------------------
char c4 = 'F' ;
char confuse( char c1 ) {
 	const char c2 = 'O' ;
 	char c3 = c1 ;
 	if ( c1 >= 'N' ) return c3 ;
 	else return c2 ;
}
void mixup( char &c1, char c2, char c3 ) {
 	cout << c1 << c2 << c3 << c4 << endl ;
 	c1 = confuse( c3 ) ;
 	c2 = 'S' ;
 	c3 = 'I' ;
 	c4 = confuse( c2 ) ;
}

void Q6(){
	char c1 = 'H' ;
 	char c2 = 'C' ;
 	char c3 = 'E' ;
 	//NOTE HERE!
 	mixup( c2, c1, c3 ) ;
 	{
 		char c3 = 'G' ;
 		cout << c1 << c2 << c3 << c4 << endl ;
 	}
 	cout << confuse( c4 ) << c1 << c2 << c3 << c4 << endl;
}

//---------------------------------------Q8-------------------------------------------------
//7
mT *func1( mT a ) {
 	//8
 	mT b ;
 	//9
 	mT* c = new mT() ;
 	cout << "----f1----" << endl;
 	//7
 	return c;
}
//3
void func2( mT d ) {
	//4
 	mT e ;
 	//5
 	mT* f = new mT() ;
 	//6
 	mT *g = func1( e ) ;
 	// POINT X
 	cout << "----X---" << endl;
}
int Q8( ) {
	//1
 	mT h ;
 	//2
 	mT* i = new mT() ;
 	func2( h ) ;
 return 0 ;
}
//-----------------------------------Q9------------------------------------------------------

void Q9(){
	int x;
	while(cin.eof() != true){
		cin >> x;
		if(cin.fail() == true){
			cout << "enconter END" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			break;
		}
		else{
			cout << "Number is " << x << endl;
		}
	}
}

int main(int argc, char const *argv[]){
	Q8();

	return 0;
}