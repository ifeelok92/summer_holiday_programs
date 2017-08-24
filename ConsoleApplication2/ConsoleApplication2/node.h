
#pragma once
class node
{
public:
	char data;
	int freq;
	node* lkid;
	node* rkid;
	//queue<char> code;
	//map<char, queue<char>> rec;
	node();
	node(char d, int f);
	void fill(char d,int f);
	
};

struct _less_than {
	bool operator()(const node* a, const node* b)const {
		return (a->freq > b->freq);
	}
};


node* build_tree(priority_queue<node*, vector<node*>, _less_than>& pq, node*p, int n);
void traverse(node* root,string str);
void test_huff();
