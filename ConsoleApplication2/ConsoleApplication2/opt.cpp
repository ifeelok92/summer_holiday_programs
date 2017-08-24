#include "stdafx.h"
#include "opt.h"

/*
void ini_zero_mat(int** mat, int n) {
	mat = new int*[n];
	for (int i = 0; i < n; i++) {
		mat[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] = 0;
		}
	}
}

void collect_mat(int** mat, int n) {
	for (int i = 0; i < n; i++) {
		delete[] mat[i];
		mat[i] = nullptr;
	}
	delete[] mat;
	mat = nullptr;

}
*/

//use recursion formula to compute m[i][j] directly
int top_to_bottom_opt(int i, int j,int* p,int** s) {
	if (i == j) {
		return 0;
	}
	if (j == i + 1) {
		s[i][j] = i;
		return p[i - 1] * p[i] * p[i + 1];
	}
	int temp;
	s[i][j] = i;
	int min = top_to_bottom_opt(i, i, p,s) + top_to_bottom_opt(i + 1, j, p,s);
	for (int k = i+2; k <= j; k++) {
		temp = top_to_bottom_opt(i, k - 1, p,s) + top_to_bottom_opt(k, j, p,s);
		if (temp < min) {
			min = temp;
			s[i][j] = k - 1;
		}
	}
	return min;

}

void show(int** p,int n,ostream & os)
{
	
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (i > j) os << "\t\t";
			else {
				os << "[" << i << "," << j << "] " << p[i][j] << "\t";
			}
		}
		os << endl;
	}
	os << endl;
}

//dim chain: p0*p1 p1*p2 ... p_n-1*p_n in array p
//opt count: m
//best break point: s
//n: number of matrices

void bottom_to_top_opt(int ** m, int n, int * p, int ** break_location)
{
	int best_location;
	int temp;
//	for (int i = 1; i <= n; i++) m[i][i] = 0;

	for (int i = 1; i < n; i++) {
		m[i][i + 1] = p[i - 1] * p[i] * p[i + 1];
		break_location[i][i+1] = i;
	}

	for (int increment = 2; increment < n; increment++) {
		for (int begin = 1; begin <= n - increment; begin++) {
			int end = begin + increment;
			m[begin][end] = m[begin][begin] + m[begin + 1][end] + p[begin - 1] * p[begin] * p[end];
			break_location[begin][end] = begin;

			//for m[begin][end], to find the best break location by running through
			//all possible locations from begin+1 to end-1
			for (best_location = begin + 1; best_location < end; best_location++) {
				temp = m[begin][best_location] + m[best_location + 1][end]\
					+ p[begin - 1] * p[best_location] * p[end];
				if (temp < m[begin][end]) {
					m[begin][end] = temp;
					break_location[begin][end] = best_location;
				}
			}


		}
	}

}



void trace_break_position(int i,int j,int** s, ostream & os) {
	if (i == j) return; //不要漏退出条件
	os << "break position for A" << i << " and A" << j << " is " << s[i][j] << endl;
	trace_break_position(i, s[i][j],s, os);
	trace_break_position(s[i][j] + 1, j, s,os);
}

int memo(int i, int j, int ** m, int * p, int ** s)
{
	if(i==j){
		s[i][i] = i;
		return 0;
	}
	if (j == i + 1) {
		s[i][j] = i;
		m[i][j] = p[i-1] * p[i] * p[j];
	}
	if (m[i][j] > 0) return m[i][j];

	int temp;
	s[i][j] = i;
	int min = memo(i, i, m, p, s) + memo(i + 1, j, m, p, s);
	for (int k = i + 2; k <= j; k++) {
		temp = memo(i, k - 1, m, p, s) + memo(k, j, m, p, s);
		if (temp < min) {
			min = temp;
			s[i][j] = k - 1;
		}
	}
	m[i][j] = min;
	return min;


}
