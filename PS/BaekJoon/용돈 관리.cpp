#include <iostream>
#include <vector>

using namespace std;

int n,m;
int a[100001];

bool go(int mid) {
	int cnt=1;
	int sum=mid;
	
	for(int i=0; i<n; i++) {
		if(mid<a[i]) return false;
		if(sum-a[i]<0) {
			sum=mid;
			cnt++;	
		}
		sum-=a[i];
	}
	
	return cnt<=m;
}

int main() {
	cin>>n>>m;
	
	int sum=0;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		sum+=a[i];
	}

	int left=1, right=1e9+1;
	int ans=0;
	while(left<=right) {
		int mid=(left+right)/2;

		// comparsion
		if(go(mid)) {
			right=mid-1;
			ans=mid;
		} else {
			left=mid+1;
		}
	}
	cout<<ans;

	return 0;
}
