#include "stdafx.h"
typedef struct {
	bool is_chosen;
	int start;
	int finish;
}activity;

void pick_activity(activity* a, int size);


void show_activity(activity * a, int size);



void compress(int n, int p[], int s[], int keep[], int bit[]);
void test_compress();
void trace_back(int, int[], int[], queue<int>&);
inline int lb(int);