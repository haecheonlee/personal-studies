#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int a[100001];

bool go(int size) {
	int cnt=1;
	int sum=0;
	
	for(int i=0; i<n; i++) {
		if(sum+a[i]>size) {
			cnt+=1;
			sum=a[i];
		} else {
			sum+=a[i];
		}
	}
	
	return cnt<=m;
}

int main() {
	cin>>n>>m;

	int left=0;
	int right=0;
	
	for(int i=0; i<n; i++) {
		cin>>a[i];
		
		if(left<a[i]) left=a[i];
		right+=a[i];
	}

	int ans=0;
	while(left<=right) {
		int mid=(left+right)/2;
		if(go(mid)) {
			ans=mid;
			right=mid-1;
		} else {
			left=mid+1;
		}
	}
	cout<<ans;

	return 0;
}

/*
INPUT:
9 3
1 2 3 4 5 6 7 8 9

OUTPUT:
17
*/
