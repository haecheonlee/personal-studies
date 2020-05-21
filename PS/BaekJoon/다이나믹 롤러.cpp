#include <iostream>
#include <algorithm>
#define ull unsigned long long

using namespace std;

int main() {
	int n;
	cin>>n;
	
	ull a[n];
	ull b[n];
	
	for(int i=0; i<n; i++) cin>>a[i];
	for(int i=0; i<n; i++) cin>>b[i];

	for(int i=0; i<n; i++) {
		int pos=upper_bound(b, b+n, a[i])-b;
		cout<<pos-i-1<<" ";
	}

	return 0;
}
