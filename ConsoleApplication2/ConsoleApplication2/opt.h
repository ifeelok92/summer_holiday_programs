#include "stdafx.h"

//find the least multiplication times
//dim chain: p0*p1 p1*p2 ... p_n-1*p_n in array p
//opt count: m
//best break point: s
//n: number of matrices
//NOTICE: INDEX START FROM 1
void bottom_to_top_opt(int** m, int n, int *p, int** break_location);

int top_to_bottom_opt(int i,int j,int *p,int** s);

//show the entries of the matrix
void show(int** p, int n, ostream & os=cout);

//construct optimal solution by recursion
void trace_break_position(int i, int j, int** s, ostream & os = cout);

//top-to-bottom by memo 
int memo(int i, int j, int** m, int* p, int** s);

int max_sum(int* a, int len, int& besti, int &bestj);
void test_max_sum();

int max_sub_sum(int*a, int s, int f);
void test_divide_and_conq();