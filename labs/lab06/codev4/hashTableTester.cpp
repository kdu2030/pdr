#include <iostream>
#include "hashTable.h"
using namespace std;

hashTable insert(string value){
   hashTable table;
   table.insert(value);
   table.insert("wjeoiweiofjfwoefjwoeijf");
   return table;
}

int main(){
   hashTable test = insert("hello");
   //cout << test.getSize() << endl;
   cout << test.find("hello") << endl;
   return 0;  

}