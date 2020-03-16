#include <iostream>
#include <algorithm>

using namespace std;

int n,c;
int a[200001];

bool check(int x) {
	int cnt=1;
	int last=a[0];
	
	for(int house : a) {
		if(house-last>=x) {
			cnt+=1;
			last=house;
		}
	}
	
	return cnt>=c;
}

int main() {
	cin>>n>>c;
	
	for(int i=0; i<n; i++) cin>>a[i];
	sort(a,a+n);
	
	int left=1,right=a[n-1]-a[0],ans=0;
	while(left<=right) {
		int mid=(left+right)/2;
		
		if(check(mid)) {
			ans=max(ans,mid);
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
5 3
1
2
8
4
9

OUTPUT:
3
*/
