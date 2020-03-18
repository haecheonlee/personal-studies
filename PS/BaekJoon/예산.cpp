#include <iostream>

using namespace std;

int n,m, ans=-1;
int a[10001];

bool check(int mid) {
	int sum=0;
	for(int i=0; i<n; i++) {
		if(a[i]>=mid) sum+=mid;
		else sum+=a[i];
	}
	return sum<=m;
}

void solve(int left, int right) {
	while(left<=right) {
		int mid=(left+right)/2;
		if(check(mid)) {
			ans=max(ans,mid);
			left=mid+1;
		} else {
			right=mid-1;
		}
	}
}

int main() {
	cin>>n;
	int mx=-1;
	for(int i=0; i<n; i++) { 
		cin>>a[i];
		mx=max(mx,a[i]);	
	}
	cin>>m;
	
	solve(0,mx);
	
	cout<<ans;
	
	return 0;
}

/*
INPUT:
4
120 110 140 150
485

OUTPUT:
127
*/
