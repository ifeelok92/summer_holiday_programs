#include "stdafx.h"
#include "activity.h"

void pick_activity(activity * a, int size)
{
	a[1].is_chosen = true;
	int current = 1;
	for(int i=2;i<=size;i++){
		if (a[i].start > a[current].finish) {
			a[i].is_chosen = true;
			current = i;
		}
	}
	
}
void show_activity(activity * a, int size)
{
	cout << "activities chosen are as follows:" << endl;
	for (int i = 1; i <= size; i++) {
		if (a[i].is_chosen) {
			cout << i << "\t";
		}
	}
	cout << endl;
}
