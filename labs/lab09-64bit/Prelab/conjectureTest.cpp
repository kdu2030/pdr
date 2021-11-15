#include <iostream>
using namespace std;

//Need to figure out a way to get mod
int collatz(int n){
	if(n == 1){
		return 0;
	}
	if(n%2 == 0){
		return 1 + collatz(n/2);
	}
	return 1 + collatz(3*n+1);
}

int main(){
	int num = 0;
	cout << "Enter a positive integer: ";
	cin >> num;
	cout << collatz(num) << endl;
	return 0;
}
