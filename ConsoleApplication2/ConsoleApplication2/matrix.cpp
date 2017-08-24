#include "stdafx.h"
#include "matrix.h"


matrix::matrix(int row, int col)
{
	if (row < 1 || col < 1) {
		cerr << "wrong input" << endl;
		exit(-1);
	}
	r = row;
	c = col;

	p = new int*[r];
	for (int i = 0; i < r; i++) {
		p[i] = new int[c];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			p[i][j] = 0;
		}
	}
}




void matrix::cin_entry()
{
	cout << "Please enter entries for a " << r << "*" << c << " matrix" << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> p[i][j];
		}
	}
}


void matrix::display()
{
	if(p==nullptr){
		cerr << "no data" << endl;
		exit(-1);
	}
	for (int i = 0; i < r; i++) {
		cout << "[";
		for (int j = 0; j < c-1; j++) {
			cout << p[i][j] << " ";
		}
		cout << p[i][c-1] << "]" << endl;
	}
	cout << endl;
}


 void matrix::mul(matrix & a, matrix & b)
{
	if (a.c != b.r||a.p==nullptr||b.p==nullptr) {
		cerr << "cannot be multiplied" << endl;
		exit(-1);
	}
	
	r = a.r;
	c = b.c;
	p = new int*[r];
	for (int i = 0; i < r; i++) {
		p[i] = new int[c];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int sum = 0;
			for (int k = 0; k < a.c; k++) {
				sum += a.p[i][k] * b.p[k][j];
			}
			p[i][j] = sum;
		}
	}



}


matrix::~matrix()
{
	for (int i = 0; i < r; i++) {
		delete[] p[i];
		p[i] = nullptr;
	}
	delete[] p;
	p = nullptr;
}
