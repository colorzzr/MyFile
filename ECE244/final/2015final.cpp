#include <iostream>
#include <cstdlib>

using namespace std;

void Q7(){
	int** yy = new int*[3];
	int*** xx = &yy;
	for(int i = 0; i < 3; i++) yy[i] = new int (i);
	for(int i = 0; i < 3; i++) cout << *(yy[i]) << endl;

}

void func(int*& a, int* b, int* c){
	a[0]	=	5;	a[1]	=	6;
	c[0]	=	7;	c[1]	=	8;
	a = c;				
	a[0]	=	9;	a[1]	=	10;
	b[0]	=	11;	b[1]	=	12;
}

void Q9(){

int* m = new int[2]; 
int* n = new int[2];

m[0] = 1;	m[1] = 2;
n[0] = 3;	n[1] = 4;

func(m, m, n);
 
cout << m[0] << "-" << m[1] <<	" "	<< n[0] <<	"II"	<< n[1] << endl;

}

// class B {
// public:
// 	B() ;
// 	virtual void Foo() ;
// } ;
// class D : public B { public:
// 	D() ;
// 	void Foo() ;
// } ;
// B::B() { this->Foo() ;}
// void B::Foo() { cout << "B::Foo()" << endl ; }
// D::D() { this->Foo(); }
// void D::Foo() { cout << "D::Foo()" << endl; } 

// void Q14(){
// 	D objectD;
// }

class B { 
protected:
	virtual void Foo() { cout << "B::Foo()" << endl ; }
public:
	void Boo() { Foo() ; cout << "B::Boo()" << endl ;}
	virtual void Hoo() { /* deliberately left empty */ }
};


class D : public B{
protected:
	virtual void Foo() { cout << "D::Foo()" << endl ; } 
public:
	void Boo() { Foo() ; cout << "D::Boo()" << endl ; } 
	virtual void Hoo(){};
};

class E : public D {
public:
void Foo() { cout << "E::Foo()" << endl ; }
void Boo() { Foo() ; cout << "E::Boo()" << endl ; } void Hoo() { /* deliberately left empty */ }
};

void Q15(){

	B bObj, *bPtr ;
	D dObj, *dPtr ;
	E eObj, *ePtr ;
	bPtr = &eObj ; 
	ePtr = &eObj ;
	bPtr -> Boo() ; 
	// bPtr -> Hoo() ;	
	// eObj.Boo() ; 
	// eObj.Hoo();

}

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

void processArrayMore( int data[], int a, int c, int b ) { 
	if( data[a] > data[c+1] )
		swap( data[a], data[c+1] ) ;
}
void processArray( int data[], int a, int b ) { 
	if( a >= b ) return ;
	int c = (a+b)/2 ;
	processArray( data, a, c ) ;
	processArray( data, c+1, b ) ; 
	processArrayMore( data, a, c, b ) ;
}
 
void Q17() {
int data[8] = 	{ 4, 10, 3, 16, 2, 1, 5, 7 } ;
processArray( data, 0, 7 ) ;
cout << data[0] << endl ;
//cout << data[1] << endl ;

int data2[8] = { 1, 2, 3, 4, 5, 6, 7, 8 } ;
processArray( data2, 0, 7 );
cout << data2[0] << endl ;
}

void lini(int n){
	for(int i = 0; i < n; i++) cout << i << endl;
	//cout << 1 << endl;
}

void f(int n){
	if( n > 0 ){
		lini(n);
		f( n/2 );
		cout << 1 << endl;
	}
}

int main(int argc, char const *argv[]){
	f(20);


	return 0;
}