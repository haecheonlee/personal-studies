#include <iostream>

using namespace std;

void print(int *a, int n) {
	for(int i=0; i<n; i++) {
		cout<<*(a+i)<<" ";
	}
	cout<<endl;
}

bool next_permutation(int *a, int n) {
	int i=n-1;
 
	while(i>0 && a[i-1]>=a[i]) i-=1;
	if(i<=0) return false;
 
	int j=n-1;
	while(a[j]<=a[i-1]) j-=1;
	swap(a[j], a[i-1]);
 
	j=n-1;
	while(i<j) {
		swap(a[i], a[j]);
		i+=1; j-=1;
	}
 
	return true;
}
 
int main(void) {
	const int n=4;
	int a[n]={1, 2, 3, 4};
	
	do{
		print(a, n);
	}while(next_permutation(a, n));
 
	return 0;
}
