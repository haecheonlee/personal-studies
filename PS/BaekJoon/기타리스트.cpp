#include <iostream>

using namespace std;

bool d[101][1001];

int main() {
	int n,s,m;
	cin>>n>>s>>m;
	
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	
	d[0][s]=true;
	for(int i=0; i<n; i++) {
		for(int j=0; j<=m; j++) {
			if(d[i][j]) {
				if(j-a[i]>=0) d[i+1][j-a[i]]=true;
				if(j+a[i]<=m) d[i+1][j+a[i]]=true;
			}
		}
	}
	
	int ans=-1;
	for(int i=0; i<=m; i++) {
		if(d[n][i]) ans=i;
	}
	cout<<ans;
	
	return 0;
}

/*
INPUT:
3 5 10
5 3 7

OUTPUT:
10
*/
