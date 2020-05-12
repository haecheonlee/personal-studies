#include <iostream>

using namespace std;

int main() {
	unsigned long long n,m;
	cin>>n>>m;
	
	unsigned long long a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	
	unsigned long long left=0;
	unsigned long long right=1e19;

	unsigned long long ans=0;
	while(left<=right) {
		unsigned long long mid=(left+right)/2;
		
		unsigned long long cnt=0;
		for(int i=0; i<n; i++) cnt+=mid/a[i];
		
		if(cnt<m) {
			left=mid+1;
		} else {
			right=mid-1;
			ans=mid;
		}
	}
	cout<<ans;

	return 0;
}

/*
INPUT:
7 10
3
8
3
6
9
2
4

OUTPUT:
8
*/
