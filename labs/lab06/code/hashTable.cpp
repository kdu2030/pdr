#include <iostream>
#include <list>
#include <vector>
#include <cmath>
#include "hashTable.h"
using namespace std;

hashTable::hashTable(){
   table = vector<list<string>>(113);
}

bool checkprime(unsigned int p);
int getNextPrime (unsigned int n); 


hashTable::hashTable(unsigned int numItems){
   int size = getNextPrime(numItems);
   table = vector<list<string>>(size);
}

hashTable::hashTable(unsigned int numItems, double loadFactor){
   int size = (int)(getNextPrime(numItems) * (1/loadFactor));
   table = vector<list<string>>(size);
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
   int tableSize = table.size();
   for(int i = 0; i < value.length(); i++){
      index += value.at(i) * pow(37, i);
   }
   return index%tableSize;
}

void hashTable::insert(string value){
   int index = hash(value);
   table.at(index).push_front(value);
}

/**
@return -1 if not found, the index inside the hash table otherwise
*/
int hashTable::find(string value){
   unsigned int index = hash(value);
   //If the hash bucket is 0
   if(table.at(index).size() == 0){
      return -1;
   }
   
   //Iterate through the entire linked list (hash table bucket)
   for(list<string>::iterator i = table.at(index).begin(); i != table.at(index).end(); i++){
      if(*i == value){
         return index;
      }
   }
   return -1;
}
