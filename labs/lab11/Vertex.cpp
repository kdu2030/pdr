#include <iostream>
#include <vector>
#include "Vertex.h" 
using namespace std;

Vertex::Vertex(string value){
	this->value = value;
	indegree = 0;
}

string Vertex::getValue(){
	return value;
}	

int Vertex::getIndegree(){
	return indegree;
}

void Vertex::setIndegree(int indegree){
	this->indegree = indegree;
}
