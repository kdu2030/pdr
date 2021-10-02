#include <iostream>
#include <string>
#include <cmath>
#include <vector>

/**
 *Sources:
 *https://www.cplusplus.com/reference/cctype/isdigit/
 *https://www.w3schools.com/cpp/cpp_strings_access.asp
 *https://www.rapidtables.com/code/text/ascii-table.html
 *https://www.geeksforgeeks.org/vector-in-cpp-stl/
*/

using namespace std;

int counter(int x){
	if(x == 1){
		return 1;
	}
	else if(x % 2 == 0){
		return counter(x/2);
	}
	return 1 + counter(x/2);
}

//CONVERT TO DECIMAL FOR NOW
string converter(string num, int startBase, int endBase){
	//Digits will hold the numerical values of each of the lengths
	int digits[num.length()];
	for(int i = 0; i < num.length(); i++){
		if(isdigit(num[i])){
			digits[i] = num[i] - 48;
		}else{
			digits[i] = num[i] - 55;
		}
	}
	
	//Convert to decimal
	int decimal = 0;
	int exp = 0;
	for(int i = num.length() - 1; i >= 0; i--){
		decimal += digits[i] *  pow(startBase, exp);
	      	exp++;	
	}

	//Convert to target base
	vector<int> targetDigits;
	int quotient = decimal;
	while(quotient > 0){
		targetDigits.push_back(quotient%endBase);
		quotient = quotient/endBase;
	}
	
	string result = "";
	//rbegin stands for reverse begin. It starts at the last element and moves towards the beginning
	//rend() points to the empty space before the first element
	for(vector<int>::reverse_iterator i = targetDigits.rbegin(); i != targetDigits.rend(); i++){
	//Need a * becuase i is a pointer
		result += to_string(*i);
	}
	return result;
}

int main(int argc, char * argv[]){
	//NOTE: Change this when adding base converter
	if(argc == 5){
		string countInput = argv[1];
		int count = counter(stoi(countInput));

		string numInput = string(argv[2]);
		int startBase = stoi(string(argv[3]));
		int endBase = stoi(string(argv[4]));

		cout << countInput << " has " <<  count << " bit(s)" << endl;
		cout << numInput << " (base " << startBase << ") = " << converter(numInput, startBase, endBase) << " (base " << endBase << ")"<<endl;
	}
	else{
		cout << "Error: Wrong number of inputs" << endl;
	}
	return 0;
	
}
