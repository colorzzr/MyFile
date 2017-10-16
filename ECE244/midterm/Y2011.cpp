#include <iostream>
#include <cstdlib>

using namespace std;


void Q4updatePTR(int* &ptr){
	*ptr = 10;
}

void Q4(){

	int* ptr = new int(8);
	cout << *ptr << endl;
	Q4updatePTR(ptr);
	cout << *ptr << endl;
}
//------------------------------------------Q5---------------------------------------------

int Q5F9(const int &x){
	//x = x + 1;
	return (x + 2);
}

//watch out !one is pbr, one is pbv
int Q5F10(int &a, int b){
	a = a + b;
	b = a + b;
	return(a + b);
}

void Q5(){

	//Fragement 2
	// int x = 1;
	// int* y = &x;
	// int* z = y;
	// *z = 2;
	// cout << x << endl;

	//Fragement 3
	// int a[2];
	// a[0] = 1;
	// a[1] = 2;
	// int* c = a;
	// c[1] = 3;
	// a[1] = a[1] + 1;
	// cout << a[1] << endl;

	//Fragement 4
	// int a[2];
	// a[0] = 1;
	// a[1] = 2;
	// int* c = &a[1];
	// *c = *c + 1;
	// cout << *c << endl;
	//cout << "testy" << endl;

	//Fragement 5
	// int a = 0;
	// int* x = &a;
	// int** y = &x;
	// *x = 1;
	// cout << **y << endl;

	//Fragement 6
	// int a = 0;
	// int* x = NULL;
	// int** y = &x;
	// x = &a;
	// **y = 3;
	// cout << a << endl;


	//Fragement 7
	// int a = 1;
	// int b = 2;
	// int* w = &a;
	// int* x = &b;
	// int** y = &w;
	// int** z = &x;
	// *y = x;
	// *w = 3;
	// cout << b << endl;

	//Fragement 9
	// int z = 1;
	// int y = F9(z);
	// cout << y << endl;

	//Fragement 10
	int i1 = 1, i2 = 2, i3;
	i3 = Q5F10(i1, i2);
	i3 += i1 + i2;
	cout << i3 << endl;
}

//-----------------------------------------_Q6---------------------------------------

void Q6(){
	//note here: we can touch the momery beyond the array
	//cos the size is the size of memory not the limit
	int MAX = 10;
	int list[MAX];
	int sum = 0;
	for(int i = 0; i < 20; i++){
		list[i] = i;
		cout << list[i] << endl;
	}
	for (int i = 0; i < 20; i++)
		sum = sum + list[i];
	cout << sum << endl;

}

//-----------------------------------------QQQQQQQQQ7-----------------------------------


void Q7(){
	int n;
	cout << "printmultiples";
	cin >> n;
	if(cin.fail() == true){
		cin.clear();
		cin.ignore(1000, '\n');
	}
	else{
		for(int i = 0; i < n; i++){
			int emplnum;
			cin >> emplnum;
			if(cin.fail() == true){
				cin.clear();
				cin.ignore(1000, '\n');
				break;
			}
			else{
				cout << "OUTPUT " << emplnum << endl;
			}
		}
		cout << "Done" << endl;
	}

}
//--------------------------------------Q10---------------------------------------------------
class BaseC{
private:
	int a, b;
	void help(){
		cout << "HELP" << endl;
	}
public:
	int c, d;
	void print(){
		cout << "hh" << endl;
	}
};

void Q10(){
	BaseC base;
	BaseC* baseptr = new BaseC();
	//fail: private member
	base.a = 0;
	//good: public
	base.c = 0;
	//good: public
	base.print();
	//fail: invalid usage of constructor
	base.BaseC();
	//fail: nohelp is the scope
	baseptr->nohelp();
	//fail: no constructor in the class
	BaseC A(0);
	//fail: cannot detect the this
	this->print();
	//fail: expect pointer
	delete base;
	//fail: require left operand
	&base = baseptr;
	//good: pointer 
	(*baseptr).c = 5;
}


int main(int argc, char const *argv[]){
	Q10();
	return 0;
}