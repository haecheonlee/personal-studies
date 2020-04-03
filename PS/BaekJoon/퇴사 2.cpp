#include <iostream>

using namespace std;

int d[2000000];

int main() {
	int n;
	cin>>n;

	int t[n], p[n];
	for(int i=0; i<n; i++) cin>>t[i]>>p[i];
	
	for(int i=0; i<n; i++) {
		d[i+t[i]]=max(d[i+t[i]], d[i]+p[i]);
		d[i+1]=max(d[i+1],d[i]);
	}
	
	cout<<d[n];

	return 0;
}

/*
INPUT:
7
3 10
5 20
1 10
1 20
2 15
4 40
2 200

OUTPUT:
45
*/
