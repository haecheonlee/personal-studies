#include <iostream>

using namespace std;

int main() {
	long long n,k,m;
	cin>>n>>k>>m;
	
	long long a[n];
	long long b[n];
	for(int i=0; i<n; i++) { 
		cin>>a[i];
		
		if(a[i]<=k) b[i]=-1;
		else if(a[i]<2*k) b[i]=a[i]-k;
		else b[i]=a[i]-(2*k);
	}
	
	long long left=1;
	long long right=1e9+1;
	
	long long ans=-1;
	while(left<=right) {
		long long mid=(left+right)/2;
		
		int cnt=0;
		for(int i=0; i<n; i++) {
			if(b[i]>0) cnt+=b[i]/mid;
		}
		
		if(cnt<m) {
			right=mid-1;
		}
		else {
			left=mid+1;
			ans=mid;			
		}
	}
	cout<<ans;

	return 0;
}

/*
INPUT:
3 6 4
20
10
3

OUTPUT:
2
*/
