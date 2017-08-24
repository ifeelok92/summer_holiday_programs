

#include "stdafx.h"
#include "matrix.h"
#include "opt.h"
#include "activity.h"
#include "seq.h"
#include "vertex.h"
#include "node.h"
#include "sort.h"

void fun1(int x) {
	x = x*x;
	cout << "in fun1" << endl;
	cout << x << endl;
}
void fun2(int x) {
	x = x*x*x;
	cout << "in fun2" << endl;
	cout << x << endl;
}


int main()
{
	test_insertion_sort();
	/*int x = 3;
	fun1(x);
	fun2(x);
	cout << "in main" << endl;
	cout << x << endl;*/
	
	/*int dim_seq[7] = { 30,35,15,5,10,20,25 };
	int num_of_mat = 6;
	matrix m(7, 7);
	matrix break_location(7, 7);*/
	/*=========================
	test 1: matrix multiplication

	matrix a(2, 3);
	a.cin_entry();
	matrix b(3, 2);
	b.cin_entry();
	matrix c;
	c.mul(a,b);
	c.display(); */

	/*============================
	test 2: find lest times of multiplication by bottom to top
	
	ofstream fout("result.txt");
	matrix m(7, 7);
	matrix break_location(7, 7);

	bottom_to_top_opt(m.p, num_of_mat, dim_seq, break_location.p);

	show(m.p, num_of_mat+1,fout);
	show(break_location.p, num_of_mat+1, fout);
	trace_break_position(1, 6, break_location.p, fout);
	*/

	/*============================
	test 3: find lest times of multiplication from top to bottom by recursion
	
	cout << top_to_bottom_opt(1, 6, dim_seq, break_location.p)<<endl;
	*/
	/*============================
	test 4: find lest times of multiplication from top to bottom by memo and recursion
	
	cout <<"memo result "<<memo(1, 6, m.p, dim_seq, break_location.p)<<endl;
	*/
	/*============================
	test 5:gready algorithm to choose activities
	activity p[12] = {
		{ false,0,0 },
		{false,1,4},{ false, 3,5},{ false, 0,6},{ false,5,7 },
		{ false,3,8 },{ false,5,9 },{ false,6,10 },{ false,8,11 },
		{ false,8,12 },{ false,2,13 },{ false, 12,14}
	};

	
	
	pick_activity(p, 11);
	show_activity(p, 11);*/

	/*============================
	test 5:dynamic programing of common max subsequence


	matrix b(len1 + 1, len2 + 1);
	common_max(x, y, c.p, b.p);
	show_common_max(v, x, len1, len2, b.p);
	char*p1 = "ABCBDAB";
	char*p2 = "BDCABA";
	int len1 = strlen(p1);
	int len2 = strlen(p2);
	seq x(len1, p1);
	seq y(len2, p2);
	matrix c(len1 + 1, len2 + 1);
	queue<char> v;
	improved_cmax(x, y, c.p);
	//c.display();
	improved_show(v, x, len1, len2, c.p);
	cout << "====================";
	cout << "\n use stack" << endl;
	while (!v.empty()) {
		cout << v.front()<<"\t";
		v.pop();
	}*/
	//test_max_sum();
	//test_divide_and_conq();
	//test_compress();
	//test_dijk();
	//test_huff();
	
	return 0;
}

