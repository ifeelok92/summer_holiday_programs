#include "stdafx.h"
int max_sum(int* a, int len, int& besti, int &bestj) {
	int sum = 0;
	int temp = 0;
	int start, end;
	for (start = 0; start < len; start++) {
		temp = 0;
		for (end = start; end < len; end++) {
			temp += a[end];
			if (temp > sum)
			{
				sum = temp;
				cout << "pos1 " << start  << "  pos2 " << end  << ";  SUM=" << sum << endl;
				besti = start + 1;
				bestj = end + 1;
			}
		}
		
	}
	return sum;
}

void test_max_sum() {
	int a[6] = { -2,11,-4,13,-5,-2 };
	int besti = 0;
	int bestj = 0;
	cout << max_sum(a, 6, besti, bestj);
	cout << "start and end position " << besti << "\t" << bestj << endl;
}

int max_sub_sum(int*a, int s, int f) {
	
	int mid, lsum, rsum, m1sum = 0, m2sum = 0;
	int sum = 0;
	if (s == f) sum = a[s]>0 ? a[s] : 0;
	else {
		mid = (s + f) / 2;
		lsum = max_sub_sum(a, s, mid);
		cout <<"left sum of ["<<s<<" ,  "<<f<<" ] is "<< lsum << endl;
		rsum = max_sub_sum(a, mid + 1, f);
		cout << "right sum of [" << s << " ,  " << f << " ] is " << rsum << endl;

		int temp1 = 0;
		int temp2 = 0;

		for (int i = mid; i >= s; i--) {
			temp1 += a[i];
			m1sum = (temp1>m1sum) ? temp1 : m1sum;
		}

		for (int i = mid + 1; i <= f; i++) {
			temp2 += a[i];
			m2sum = (temp2>m2sum) ? temp2 : m2sum;
		}
		cout << "Lmid sum of [" << s << " ,  " << f << " ] is " <<m1sum << endl;
		cout << "Rmid sum of [" << s << " ,  " << f << " ] is " << m2sum << endl;
		sum = m1sum + m2sum;
		cout << "mid sum of [" << s << " ,  " << f << " ] is " << sum << endl;
		cout << endl;
		sum = (lsum>sum) ? lsum : sum;
		sum = (rsum>sum) ? rsum : sum;
	}
	return sum;
}

void test_divide_and_conq() {
	int a[6] = { -2,11,-4,13,-5,-2 };
	cout << max_sub_sum(a, 0, 5) << endl;

}