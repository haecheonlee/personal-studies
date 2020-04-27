#include <iostream>

using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
		int n,m;
		cin>>n>>m;
		
		int a[n][m];
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) cin>>a[i][j];
		}
		
		int cnt=0;
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				if(a[j][i]==1) {
					for(int k=j+1; k<n; k++) {
						if(a[k][i]==0) cnt++;
					}
				}	
			}
		}
		cout<<cnt<<'\n';
	}

	return 0;
}

/*
INPUT:
3
5 4
1 0 0 0
0 0 1 0
1 0 0 1
0 1 0 0
1 0 1 0
3 3
1 1 1
1 1 1
0 0 0
5 6
1 0 1 1 0 1
0 0 0 0 0 0
1 1 1 0 0 0
0 0 0 1 1 1
0 1 0 1 0 1

OUTPUT:
8
6
16
*/
