#include <iostream>

using namespace std;

int a[5001];
int n,m;

int go(int mid) {
	int t1=a[0];
	int t2=a[0];
	
	int cnt=1;
	for(int i=1; i<n; i++) {
		if(t1>a[i]) t1=a[i];
		if(t2<a[i]) t2=a[i];
		
		if(t2-t1>mid) {
			t1=a[i];
			t2=a[i];
			
			cnt+=1;
		}
	}
	
	return cnt;
}

int main() {
	cin>>n>>m;
	
	int left=0;
	int right=0;
	
	for(int i=0; i<n; i++) {
		cin>>a[i];
		right=max(right,a[i]);
	}
	
	int ans=right;
	while(left<=right) {
		int mid=(left+right)/2;
		
		if(go(mid)<=m) {
			right=mid-1;
			ans=min(ans,mid);
		} else {
			left=mid+1;
		}
	}
	cout<<ans;
	
	return 0;
}

/*
INPUT:
8 3
1 5 4 6 2 1 3 7

OUTPUT:
5
*/
