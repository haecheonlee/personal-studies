#include <iostream>

using namespace std;

long long d[101][21];

int main() {
	int n;
	cin>>n;
	
	n-=1;
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	
	int goal;
	cin>>goal;
	
	d[0][a[0]]=1;
	for(int i=1; i<n; i++) {
		for(int j=0; j<=20; j++) {
			if(j-a[i]>=0) d[i][j]+=d[i-1][j-a[i]];
			if(j+a[i]<=20) d[i][j]+=d[i-1][j+a[i]];
		}
	}
	
	cout<<d[n-1][goal];
	
	return 0;
}

/*
INPUT:
11
8 3 2 4 8 7 2 4 0 8 8

OUTPUT:
10
*/
