#include <iostream>
#include <vector>

using namespace std;

vector<int> a;

int go(int m) {
	int sum=0;
	
	for(auto x : a) {
		sum+=(x/m);
		if(x%m) sum++;
	}
	
	return sum;
}

int main() {
	int n,k;
	cin>>n>>k;
	
	a.resize(k);	
	for(int i=0; i<k; i++) cin>>a[i];
	
	int l=1, r=1e9;
	int ans=0;
	while(l<=r) {
		int m=(l+r)/2;
		
		if(go(m)<=n) {
			r=m-1;
			ans=m;
		} else {
			l=m+1;
		}
	}
	cout<<ans;
	
	return 0;
}
