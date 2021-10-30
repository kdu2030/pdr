/*
*Name: Kevin Du
*Date: 10/24/2021
*ID: kd5eyn
*File: addition.cpp
*/
#include <iostream>
using namespace std;

int main(){
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int result = -1;
	while(result != 0){
		cin >> num1;
		cin >> num2;
		cin >> num3;
		result = num1 + num2 + num3;
		cout << result << endl;
	}
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;
	
	return 0;
}