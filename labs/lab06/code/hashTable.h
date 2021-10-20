#include <iostream>
#include <list>
#include <vector>
#include <cmath>

using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

class hashTable{
   public:
      hashTable();
      hashTable(unsigned int numItems);
      unsigned int hash(string value);
      void insert(string value);
      int find(string value);
      int getSize();
   private:
      vector<list<string>> table;
      int size;
};

#endif