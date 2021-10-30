#include <iostream>
using namespace std;

int main(){
	int length = 0;
	cout << "Length : ";
	cin >> length;
	int nums[length];
	int i = 0;
	//Reading input of array
	while(i < length){
		cout << i << ": ";
		cin >> nums[i];
		i++;
	}
	//Printing array forwards
	i = 0;
	while(i < length){
		cout << nums[i] << endl;
		i++;
	}
	
	//Printing array backwards
	i = length - 1;
	while(i >= 0){
		cout << nums[i] << endl;
		i--;
	}
	return 0;
}