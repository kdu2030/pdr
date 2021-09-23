#include <iostream>
#include <string>

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

int main(int argc, char * argv[]){
	//NOTE: Change this to 3 when adding base converter
	if(argc == 2){
		string countInput = argv[1];
		int count = counter(stoi(countInput));
	}
	return 0;
	
}
