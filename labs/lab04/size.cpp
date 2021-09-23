#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

void printSizes(){
	cout << "Int: " << sizeof(int) << endl;
	cout << "Unsigned Int: " << sizeof(unsigned int) << endl;
	cout << "Float: " << sizeof(float) << endl;
	cout << "Double: " << sizeof(double) << endl;
	cout << "Char: " << sizeof(char) << endl;
	cout << "Bool: " << sizeof(bool) << endl;
	cout << "Int*: " << sizeof(int*) << endl;
	cout << "Char*: " << sizeof(char*) << endl;
	cout << "Double*: " << sizeof(double*) << endl;
}

void printMax(){
	cout <<	INT_MAX << endl;
	cout << UINT_MAX << endl;
	cout << SCHAR_MAX << endl;
}


/*void zeroes(){
	int num = 0;
	unsigned int a = 0;
	float b = 0.0;
	double c = 0;
	char d = '0';
	bool e = 0;
	
}/*


void ones(){
	int num = 1;
	unsigned int a = 1;
	float b = 1;
	double c = 1;
	char d = '1';
	bool e = 1;	
}

/*
void nulls(){
	int* a = NULL;
	char* b = NULL;
	double* c = NULL;
}*/






int main(){
	/*
	int a = 1;
	double b = 1;
	char c = '@';
	int * d = &a;
	double * e = &b;
	char * f = &c;
	cout << d << endl;
	cout << e << endl;
	cout << f << endl;
	*/
	//zeroes();
	bool a = false;
	cout << a << endl;
	return 0;
}