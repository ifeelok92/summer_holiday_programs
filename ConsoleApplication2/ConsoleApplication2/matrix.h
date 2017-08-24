#pragma once



class matrix
{
public:
	int r;
	int c;
	int** p;
	//default matrix
	matrix() { p = nullptr; };
	//creat a m*n matrix, allocate memory
	matrix(int m, int n);
	//matrix multiplication
	void mul(matrix & a, matrix & b);
	//get data from std input
	void cin_entry();
	//print a matrix
	void display();
	
	~matrix();
};

