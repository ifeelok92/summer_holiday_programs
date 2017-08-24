#pragma once
class seq
{
public:
	int size;
	char* ch;
	seq(int len,char* p);
	~seq();
};
void common_max(seq&, seq&, int**, int**);
void improved_cmax(seq&, seq&, int**);

void show_common_max(queue<char>& v, seq& s1, int i, int j, int** b);

void improved_show(queue<char>& v, seq& s1, int i, int j, int** c);

