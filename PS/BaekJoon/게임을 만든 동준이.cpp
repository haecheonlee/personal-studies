#include <iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	
	int cnt=0;
	for(int i=n-2; i>=0; i--) {
		if(a[i]>=a[i+1]) {
			int new_score=a[i+1]-1;
			cnt+=a[i]-new_score;
			a[i]=new_score;
		}
	}
	cout<<cnt;
	
	return 0;
}

/*
boj.kr/2847

INPUT:
4
5
3
7
5

OUTPUT:
6
*/
