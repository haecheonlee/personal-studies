#include <iostream>

using namespace std;

int main() {
	long long n,k;
	cin>>n>>k;
	
	int a[n];
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	
	for(int i=0; i<n; i++) {
		k-=a[i];
		if(k<0) {
			cout<<i+1;
			return 0;
		}
	}
	
	for(int i=n-1; i>=0; i--) {
		k-=a[i];
		if(k<0) {
			cout<<i+1;
			return 0;
		}
	}
	
	return 0;
}

/*
boj.kr/18311

INPUT:
5 28
7 4 2 4 5

OUTPUT:
4
*/
