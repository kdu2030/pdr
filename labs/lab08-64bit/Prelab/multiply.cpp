#include <iostream>
#include <cmath>

using namespace std;

int power(int base, int exponent){
	if(exponent == 0){
		return 1;	
	}
	return base * power(base, exponent-1);
}

int main(){
	int x = 0;
	int y = 0;
	int result = 0;
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	for(int i = 0; i < y; i++){
		result += x;	
	}
	cout << result << endl;
	cout << power(x, y) << endl;
	return 0;
}