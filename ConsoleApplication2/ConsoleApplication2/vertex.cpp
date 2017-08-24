#include "stdafx.h"
#include "vertex.h"

const int maxint = 1024;

void vertex::ver(int i)
{
	No = i;
	dist2src = 0;
	prev = 0;
	is_in = false;
}

vertex dot[6];

void ini_graph(int** adj, int num, vertex* dot) {
	for (int i = 1; i <= num; i++) {
		dot[i].No = i;
		dot[i].dist2src = adj[1][i];
	}
}

void dijk(int** c, int num, vertex* dot, int *keep) {
	int temp;
	int latest;
	int count = 0;
	int flag;
	//queue<int> q;

	keep[1] = 1;
	dot[1].is_in = true;
	//q.push(1);

	for (int i = 2; i <= num; i++) {
		dot[i].dist2src = c[1][i];
	}

	while (keep[num] == 0) {
		count++;
		temp = maxint;
		latest = keep[count];
		for (int i = 1; i <= num; i++) {
			if (dot[i].is_in) continue;
			if (dot[i].dist2src > dot[latest].dist2src + c[latest][i])
				dot[i].dist2src = dot[latest].dist2src + c[latest][i];
			if (temp > dot[i].dist2src) {
				temp = dot[i].dist2src;
				flag = i;
				dot[i].prev = latest;
			}
		}
		cout << flag << " is adding into set.\n";
		keep[count + 1] = flag;
		dot[flag].is_in = true;

	}
	
}

void test_dijk() {
	int adj[6][6] = {
		{ 0, 0,0,0,0,0 },
		{0,0,10,maxint,30,100},
		{ 0,maxint,0,50,maxint,maxint },
		{ 0,maxint,maxint,0,maxint,10 },
		{ 0,maxint,maxint,20,0,60 },
		{ 0,maxint,maxint,maxint,maxint,maxint }
	};
	vertex dot[6];
	int keep[6] = { 0 };
	int** p;
	p = new int*[6];
	for (int i = 0; i < 6; i++) {
		p[i] = new int[6];
		dot[i].ver(i);
	}

	for (int i = 0; i < 6; i++) 
		for (int j = 0; j < 6; j++) 
			p[i][j] = adj[i][j];

	
	dijk(p, 5, dot, keep);
	for (int i = 2; i <= 5; i++) {
		cout << "distance from " << i << " to source is " << dot[i].dist2src << endl;
	}
}