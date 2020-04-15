#include <iostream>
#include <vector>

using namespace std;
const int INF=1000000000;

int d[1001][1001];

int main() {
	int n,m,x;
	cin>>n>>m>>x;
	
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

	int ans=-1;
	for(int i=1; i<=n; i++) {
		ans=max(ans,d[i][x]+d[x][i]);
	}
	cout<<ans;

	return 0;
}

/*
INPUT:
4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3

OUTPUT:
10
*/
