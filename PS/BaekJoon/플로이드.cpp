#include <iostream>

using namespace std;
const int INF=1000000000;

int d[101][101];

int main() {
	int n,m;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i==j) d[i][j]=0;
			else d[i][j]=INF;
		}
	}
	
	for(int i=0; i<m; i++) {
		int from,to,cost;
		cin>>from>>to>>cost;
		
		if(d[from][to]>cost) d[from][to]=cost;
	}
	
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(d[i][j]>d[i][k]+d[k][j]) {
					d[i][j]=d[i][k]+d[k][j];
				}
			}
		}
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(d[i][j]==INF) d[i][j]=0;
			cout<<d[i][j]<<" ";
		}
		cout<<'\n';
	}

	return 0;
}

/*
INPUT:
5
14
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
3 5 10
3 1 8
1 4 2
5 1 7
3 4 2
5 2 4

OUTPUT:
0 2 3 1 4
12 0 15 2 5
8 5 0 1 1
10 7 13 0 3
7 4 10 6 0
*/
