#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	sort(a,a+n);
	
	int diff[n-1];
	for(int i=0; i<n-1; i++) diff[i]=a[i+1]-a[i];
	sort(diff, diff+(n-1));
	
	int ans=0;
	for(int i=0; i<n-1-(k-1); i++) ans+=diff[i];
	cout<<ans;

	return 0;
}

/*
INPUT:
6
2
1 6 9 3 6 7

OUTPUT:
5
*/
