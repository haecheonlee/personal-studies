#include <iostream>

using namespace std;

int main() {
	int n;
	long long w;
	cin>>n>>w;
	
	long long a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	
	for(int i=1; i<n; i++) {
		if(a[i-1]<a[i]) {
			long long c=(w/a[i-1]);
			w+=(a[i]-a[i-1])*c;
		}
	}
	
	cout<<w;
	
	return 0;
}

/*
INPUT:
10 24
5
7
5
4
2
7
8
5
3
4

OUTPUT:
170
*/
