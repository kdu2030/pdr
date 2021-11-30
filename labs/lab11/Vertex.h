#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <vector>
using namespace std;

class Vertex {
	public:
		Vertex(string value);	
		string getValue();
		int getIndegree();
		void setIndegree(int indegree);

	
	private:
		string value;
		int indegree;

};

#endif
