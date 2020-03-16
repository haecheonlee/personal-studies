#include <iostream>

using namespace std;

int n,k;
long long a[10001];

bool check(long long x) {
	int cnt=0;
	for(int i=0; i<n; i++) {
		cnt+=(a[i]/x);
	}
	
	return cnt>=k;
}

int main() {
	cin>>n>>k;
	
	long long mx=0;
	for(int i=0; i<n; i++) {
        cin>>a[i];
        if(mx<a[i]) mx=a[i];	
	}

	long long left=1,right=mx,ans=0;
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
INPUT:
4 11
802
743
457
539

OUTPUT:
200
*/
