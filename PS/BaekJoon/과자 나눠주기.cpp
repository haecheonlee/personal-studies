#include <iostream>

using namespace std;

int main() {
	int n,m;
	cin>>m>>n;
	
	long long a[n];
	long long sum=0;
	for(int i=0; i<n; i++) { 
		cin>>a[i];
		sum+=a[i];	
	}

	if(sum/m<=0) {
		cout<<0;
		return 0;
	}

	long long left=1;
	long long right=1e9+1;
	
	int ans=0;
	while(left<=right) {
		long long mid=(left+right)/2;
		
		long long cnt=0;
		for(int i=0; i<n; i++) cnt+=a[i]/mid;
		
		if(cnt<m) {
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
3 10
1 2 3 4 5 6 7 8 9 10

OUTPUT:
8
*/
