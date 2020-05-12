#include <iostream>

using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	
	long long a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	
	long long left=1;
	long long right=1e10;

	long long ans=0;
	while(left<=right) {
		long long mid=(left+right)/2;
		
		long long cnt=0;
		for(int i=0; i<n; i++) cnt+=a[i]/mid;
		
		if(cnt<k) {
			right=mid-1;
		} else {
			left=mid+1;
			ans=mid;
		}
	}
	cout<<ans;
	
	return 0;
}

/*
INPUT:
4 11
427
541
774
822

OUTPUT:
205
*/
