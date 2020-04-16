/* shortest path - floyd warshall */
/* boj.kr/11404 */

#include <iostream>

using namespace std;
const int INF=1e9;

int d[1001][1001];
int n,m,from,to,cost;

int main() {
	cin>>n>>m;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i==j) d[i][j]=0;
			else d[i][j]=INF;
		}
	}
	
	for(int i=0; i<m; i++) {
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
