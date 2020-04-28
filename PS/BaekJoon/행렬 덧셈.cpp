#include <iostream>

using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	
	int a[n][m], b[n][m];
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) cin>>a[i][j];
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) cin>>b[i][j];
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout<<a[i][j]+b[i][j]<<" ";
		}
		cout<<'\n';
	}

	return 0;
}

/*
INPUT:
3 3
1 1 1
2 2 2
0 1 0
3 3 3
4 4 4
5 5 100

OUTPUT:
4 4 4
6 6 6
5 6 100
*/
