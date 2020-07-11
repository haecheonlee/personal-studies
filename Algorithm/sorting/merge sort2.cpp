#include <iostream>

using namespace std;
 
const int SIZE=9;

int a[SIZE]={5,2,1,7,3,8,6,9,4};
int b[SIZE];

void mergeSort(int L, int R) {
	int M=(L+R)/2;
	int i=L, j=M+1, k=0;
	
	while(i<=M && j<=R) {
		if(a[i]<=a[j]) b[k++]=a[i++];
		else b[k++]=a[j++];
	}
	
	while(i<=M) b[k++]=a[i++];
	while(j<=R) b[k++]=a[j++];
	
	for(int i=L; i<=R; i++) a[i]=b[i-L];
}

void sort(int L, int R) {
	if(L==R) return;
	
	int M=(L+R)/2;
	sort(L,M);
	sort(M+1,R);
	mergeSort(L,R);
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
