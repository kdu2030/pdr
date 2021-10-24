#include <iostream>
#include <list>
#include <vector>
#include <cmath>
#include "hashTable.h"
using namespace std;

vector<int> calcPows(int maxPow);

hashTable::hashTable(){
   table = vector<string>(113, "");
   pows = calcPows(22);
   size = 22;
}


bool checkprime(unsigned int p);
int getNextPrime (unsigned int n); 

hashTable::hashTable(unsigned int numItems, double loadFactor){
   size = (int)(getNextPrime(numItems) * (1/loadFactor));
   table = vector<string>(size, "");
   pows = calcPows(22);
}

//Populates an array with powers of 37 for the hash function
vector<int> calcPows(int maxPow){
	vector<int> pows;
	for(int i = 0; i < maxPow; i++){
		pows.push_back(pow(37, i));
	}
	return pows;
}

// yes, there are much faster -- and much better -- ways to check if a
// number is prime (see the Sieve of Eratosthenes, for one example),
// but this code will work correctly, it is fairly straightforward,
// and it is fast enough for our purposes in the hash lab
bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}

unsigned int hashTable::hash(string value){
   //Needs to be an unsigned int because could overflow
   unsigned int index = 0;
   for(int i = 0; i < value.length(); i++){
      index += value.at(i) * pows.at(i);
   }
   return index%size;
}

void hashTable::insert(string value){
	int index = hash(value);
	bool inserted = false;
	vector<string>::iterator i = table.begin() + index;
	while(!inserted){
		if(i == table.end()){
			i = table.begin();
			index = 0;
		}
		
		if(*i == ""){
			table.insert(i, value);
			inserted = true;
			return;
		}
		else{
			i++;
			index++;
		}
	}
	
}

/**
@return -1 if not found, the index inside the hash table otherwise
*/
int hashTable::find(string value){
	int index = hash(value);
	bool found = false;
	vector<string>::iterator i = table.begin() + index;
	while(!found){
		if(i == table.end()){
			i = table.begin();
			index = 0;
		}
		cout << "Target " << value << endl;
		cout << *i << endl;
		if(*i == ""){
			//Found empty space
			found = true;
			return -1;
		}
		else if(*i == value){
			//Found value
			found = true;
			return index;	
		}
		else{
			//Move forward
			i++;
			index++;
		}
	}
	return -1;
}
