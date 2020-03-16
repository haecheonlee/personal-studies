#include <iostream>

using namespace std;

long long n,m;
long long a[1000001];

bool check(long long x) {
	long long cnt=0;
	
	for(int i=0; i<n; i++) {
		if(a[i]-x>0) cnt+=(a[i]-x);
	}

	return cnt>=m;
}

int main() {
	cin>>n>>m;
	
	long long mx=-1;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		if(mx<a[i]) mx=a[i];
	}
	
	long long left=0,right=mx,ans=0;
	while(left<=right) {
		long long mid=(left+right)/2;

		if(check(mid)) {
			if(ans<mid) ans=mid;
			left=mid+1;
		} else {
			right=mid-1;
		}
	}
	
	cout<<ans;
	
	return 0;
}

/*
boj.kr/2805

INPUT:
4 7
20 15 10 17

OUTPUT:
15
*/
