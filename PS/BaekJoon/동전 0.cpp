#include <iostream>

using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	
	int ans=0;
	for(int i=n-1; i>=0; i--) {
		ans+=k/a[i];
		k%=a[i];
	}
	cout<<ans;
	
	return 0;
}

/*
INPUT:
10 4200
1
5
10
50
100
500
1000
5000
10000
50000

OUTPUT:
6
*/
