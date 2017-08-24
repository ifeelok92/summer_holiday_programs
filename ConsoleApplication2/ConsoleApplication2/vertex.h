#pragma once

class vertex
{
public:
	int No;
	int dist2src;
	int prev;
	bool is_in;
	//INPUT VAR: vertex No.
	void ver(int);
	
};

void ini_graph(int** adj, int num, vertex* dot);
void dijk(int** c, int num, vertex* dot, int *keep);
void test_dijk();