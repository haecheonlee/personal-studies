#include <iostream>

using namespace std;
const int SIZE=9;

int a[SIZE]={6,5,8,4,1,9,3,7,2};

int choosePivot(int L, int R) {
	return (L+R)/2;	
}

int partition(int L, int R) {
	int pivotIndex=choosePivot(L,R);
	int pivotValue=a[pivotIndex];
	
	swap(a[pivotIndex], a[R]);
	
	int storeIndex=L;
	for(int i=L; i<R; i++) {
		if(a[i]<pivotValue) {
			swap(a[i],a[storeIndex]);
			storeIndex++;
		}
	}
	
	swap(a[storeIndex], a[R]);
	
	return storeIndex;
}

void sort(int L, int R) {
	if(L<R) {
		int pivot=partition(L,R);
		sort(L,pivot-1);
		sort(pivot+1,R);
	}
}

void print() {
	for(int i=0; i<SIZE; i++) cout<<a[i]<<" ";
	cout<<endl;
}

int main() {
	print();
	sort(0,SIZE-1);
	print();
	
	return 0;
}
