#include "stdafx.h"
#include "sort.h"

void insertion(int *a,int n) {
	int temp;
	int keep;
	//起牌过程
	for (int i = 1; i < n; i++) {
		keep = a[i];
		for (int j = i - 1; j >= 0; j--) {
				if(keep<a[j]){
					//往后挪一位
					a[j + 1] = a[j];
					a[j] = keep;
				}
				else {
					break;
				}
		}
	}
}

void test_insertion_sort() {
	int a[6] = { 5,2,4,6,1,3 };
	insertion(a, 6);
	for (int i = 0; i < 6; i++) cout << a[i] << "\t";
	cout << endl;
}

void divide(int* a, int start,int end) {
	int mid = (start + end) / 2;

}