#include <iostream>

using namespace std;

int d[100000];
int d2[100000];

int main() {
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	
	d[0]=arr[0];
	for(int i=1; i<n; i++) {
		d[i]=arr[i];
		if(d[i]<d[i-1]+arr[i]) d[i]=arr[i]+d[i-1];
	}
	
	d2[n-1]=arr[n-1];
	for(int i=n-2; i>=0; i--) {
		d2[i]=arr[i];
		if(d2[i]<d2[i+1]+arr[i]) d2[i]=arr[i]+d2[i+1];
	}
	
	int result=d[0];
	for(int i=0; i<n; i++) {
		if(result<d[i]) result=d[i];
	}
	
	for(int i=1; i<n-1; i++) {
		if(result<d[i-1]+d2[i+1]) result=d[i-1]+d2[i+1];
	}
	
	cout<<result;
	
	return 0;
}

/*
boj.kr/13398

INPUT:
10
10 -4 3 1 5 6 -35 12 21 -1

OUTPUT:
54
*/
