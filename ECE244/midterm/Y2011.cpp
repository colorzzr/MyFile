#include <iostream>
#include <cstdlib>

using namespace std;

void Q5(){
	//Fragement 1
	// int* ptr = new int(8);
	// cout << *ptr << endl;
	// updatePTR(ptr);
	// cout << *ptr << endl;

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
	int a = 1;
	int b = 2;
	int* w = &a;
	int* x = &b;
	int** y = &w;
	int** z = &x;
	*y = x;
	*w = 3;
	cout << b << endl;


}



int main(int argc, char const *argv[]){
	/* code */
	return 0;
}