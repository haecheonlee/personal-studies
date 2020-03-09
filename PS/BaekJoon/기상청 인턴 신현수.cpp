#include <iostream>

using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	
	int a[n];
	int sum=0;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		if(i<k) {
			sum+=a[i];
		}	
	}

	int highest=sum;
	for(int i=1; i+k<=n; i++) {
		sum+=a[i+k-1]-a[i-1];
		highest=max(sum,highest);
	}
	cout<<highest;
	
	return 0;
}

/*
boj.kr/2435

INPUT:
10 2
3 -2 -4 -9 0 3 7 13 8 -3

OUTPUT:
21
*/
