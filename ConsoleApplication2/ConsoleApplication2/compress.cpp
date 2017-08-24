#include "activity.h"
#include "stdafx.h"
inline int lb(int n) {
	int k = 0;
	while (n>0) {
		n = n / 2;
		k++;
	}
	return  k;
}

//s: ǰi���������ŷֶ�����Ĵ洢bit��
//bmax(i,j): pi,...,pj �����Ҫ����bit���԰���Щ��ȫ��������
//keep[i]: ��¼p1,...,pi��Ϊ����ʱ��p1,...,pi�����Ŵ洢�ռ�
//bit[i]: ��¼piռ���ٱ���λ
void compress(int n, int p[], int s[], int keep[], int bit[]) {
	//p start from 0
	//else start from 1
	int tmin, lbmax = 0;
	cout << "No.0 " << bit[0] << endl;
	for (int i = 0; i < n; i++) {
		bit[i + 1] = lb(p[i]);
		cout << "No." << i + 1 << "  "<<bit[i + 1] << " bit(s) " << endl;
	}
	s[1] = bit[1] + 11;
	cout << "s[1] = " << s[1] << endl;
	if (n == 1) {  return; }
	for (int i = 2; i<=n; i++) {
		//cout << "\n ====================" << endl;
		//cout << "i=" << i << endl;
		lbmax = bit[i];
		lbmax = (bit[i - 1] > bit[i]) ? bit[i - 1] : bit[i];
		s[i] = s[i - 1] + lbmax;
	//	cout << "s[" << i << "] = " << s[i] << "\n";

		
		keep[i] = i-1;

		//cout << "\n decreasing" << endl;
//////////////////k��1������2��ʼ����ʱע�͵���32�У�����Ȼlbmax���� or ���յ�32����
		for (int k = 2; k <= i; k++) {
		//	cout << "\nk=" << k<< endl;
			
			//cout << "this round lbmax is " << lbmax << endl;

		//	cout << "s[" << i - k << "]=" << s[i - k] <<" k*lbmax="<<k*lbmax <<endl;
			tmin = s[i - k] + k*lbmax ;
		//	cout << "temporary s["<<i<<"] = " << tmin<<endl;

			lbmax = (bit[i - k]>lbmax) ? bit[i - k] : lbmax;
		//	cout << "next round lbmax is " << lbmax << endl;

			if (tmin<s[i]) {
				keep[i] = i - k;
				s[i] = tmin;
		//		cout << "s[" << i << "] = " << s[i] <<  endl;

				
			}
			else {
				//cout << "jump k=" <<k<< endl;
			}
		}
	//	cout << "before adding 11, s[" << i << "] = " << s[i] << endl;
	//	cout << endl;
		s[i] += 11;
		cout << "  s[" << i << "] = " <<s[i]<<endl;
		cout << "keep[" << i << "]=" << keep[i] << "\n\n";
	}

}

void trace_back(int n, int s[], int keep[], queue<int>& q) {
	if (keep[n] == 0) { q.push(0); return; }
	trace_back(keep[n], s, keep, q);
	q.push(keep[n]);
}

void test_compress() {
	const int n = 7;
	int p[6] = {10,12,15,255,1,2 };
	for (int i = 0; i < 6; i++) {
		cout << p[i] << "\t";
	}
	cout << endl;
	int s[7] = { 0 };
	int keep[7] = { 0 };
	int bit[7] = { 0 };
	queue<int> q;
	compress(6, p, s, keep, bit);
	trace_back(6, s, keep,q);
	cout << q.size() << " segment(s), and \n break positions are " << endl;
	while (!q.empty()) {
		cout << q.front()<<"  ";
		q.pop();
	}
	cout << "\nminimal storage bits are " << s[6] << endl;
	cout << endl;


}