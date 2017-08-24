#include "stdafx.h"
#include "seq.h"




seq::seq(int len,char* p)
{
	size = len;
	ch = new char[size];
	ch = p;
	cout << "seq: " << ch << endl;
}

seq::~seq()
{
	delete[] ch;
	ch = nullptr;
}

void common_max(seq& seq1, seq& seq2, int** c, int ** b) {
	int index1, index2;
	
	for (int k = 1; k <=seq2.size; k++) {
		c[0][k] = 0;
	}
	for (int k = 1; k <= seq2.size; k++) {
		c[k][0] = 0;
	}

	for (index1 = 1; index1 <= seq1.size; index1++) {
		for (index2 = 1; index2 <= seq2.size; index2++) {
			if (seq1.ch[index1-1] == seq2.ch[index2-1])
			{
				c[index1][index2] = c[index1 - 1][index2 - 1]+1;
				b[index1][index2] = 1;
			}
			else {
				if(c[index1 - 1][index2] >= c[index1][index2 - 1]) 
				{c[index1][index2] = c[index1 - 1][index2];
				b[index1][index2] = 2;
				}
				else
				 {c[index1][index2] = c[index1][index2 - 1]; 
				 b[index1][index2] = 3;
				};
			}
		}
	}
}

void improved_cmax(seq &seq1, seq &seq2, int **c)
{
	int index1, index2;

	for (int k = 1; k <= seq2.size; k++) {
		c[0][k] = 0;
	}
	for (int k = 1; k <= seq2.size; k++) {
		c[k][0] = 0;
	}

	for (index1 = 1; index1 <= seq1.size; index1++) {
		for (index2 = 1; index2 <= seq2.size; index2++) {
			if (seq1.ch[index1 - 1] == seq2.ch[index2 - 1])
			{
				c[index1][index2] = c[index1 - 1][index2 - 1] + 1;
				//b[index1][index2] = 1;
			}
			else {
				if (c[index1 - 1][index2] >= c[index1][index2 - 1])
				{
					c[index1][index2] = c[index1 - 1][index2];
				//	b[index1][index2] = 2;
				}
				else
				{
					c[index1][index2] = c[index1][index2 - 1];
				//	b[index1][index2] = 3;
				};
			}
		}
	}
}

void show_common_max(queue<char>& v,seq& s1, int i, int j, int** b) {
	if (i == 0 || j == 0) return;
	
	if (b[i][j] == 1) {
		show_common_max(v, s1, i - 1, j - 1, b);
		v.push(s1.ch[i-1]);
		cout << s1.ch[i - 1];
	}
	else if(b[i][j] == 2) show_common_max(v, s1, i - 1, j, b);
	     else show_common_max(v, s1, i, j-1, b);
}

void improved_show(queue<char>& v, seq & s1, int i, int j, int ** c)
{
	if (i == 0 || j == 0) return;
	//cout << "c[" << i << "][" << j << "]=" << c[i][j] << endl;
	//cout << "c[" << i - 1 << "][" << j-1 << "]=" << c[i - 1][j-1] << endl;
	//cout << "c[" << i-1 << "][" << j << "]=" << c[i-1][j] << endl;
	//cout << "c[" << i << "][" << j-1 << "]=" << c[i][j-1] << endl;
	if (c[i][j] ==( c[i-1][j-1]+1)) {
		//cout << "1" << endl;
		improved_show(v, s1, i - 1, j - 1, c);
		v.push(s1.ch[i - 1]);
		cout << s1.ch[i - 1];
	}
	else if (c[i][j] == c[i - 1][j]) {
		improved_show(v, s1, i - 1, j, c);
		//cout << "2" << endl;
	}
	else {
		improved_show(v, s1, i, j - 1, c);
		//cout << "3" << endl;
	}
}
