#include "stdafx.h"
#include "node.h"




node::node()
{
	
	lkid = nullptr; 
	rkid = nullptr;
}

node::node(char d, int f)
{
	data = d; freq = f;
}

void node::fill(char d, int f)
{
	data = d; freq = f;
}



//priority_queue<Toast, vector<Toast>, ToastCompare>

node* build_tree(priority_queue<node*, vector<node*>, _less_than>& pq, node*p, int n)
{
	for (int i = 0; i < n; i++) {
		pq.push(&p[i]);
	}

	while (1){
		node* l = new node(*pq.top());
		cout << l->data<<"\t";
		pq.pop();
		node* r = new node(*pq.top());
		cout << r->data << "\n";
		pq.pop();
		
		node* fa = new node('$', l->freq + r->freq);
		fa->lkid = l;
		fa->rkid = r;
		if(!pq.empty()) pq.push(fa);
		else { 
			cout << "end of priority queue" << endl;
			return fa; }
	}
	
}
//这里拷贝用的妙，str放到实参里面，不会被改变，而得到的是实参的拷贝。
void traverse(node* root,string str) {
	if (root->data != '$') {
		cout << "\t" << root->data << "\t" << str << endl;
		return;
		}
	traverse(root->lkid,str+"0");
	traverse(root->rkid,str+"1");
}

void test_huff()
{
	int num = 6;
	node* p = new node[6];
	p[0].fill('a',45);
	p[1].fill('b',13);
	p[2].fill('c',12);
	p[3].fill('d',16);
	p[4].fill('e',9);
	p[5].fill('f',5);
	priority_queue<node*, vector<node*>, _less_than> pq;
	node* rt = new node;
	rt=build_tree(pq, p, num);
	traverse(rt,"");
}


