#include <iostream>

using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	
	int a[n][m];
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) cin>>a[i][j];
	}
	
	int dist[n][m];
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) dist[i][j]=-1;
	}

	dist[0][0]=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			int current=a[i][j];
			if(dist[i][j]==-1) continue;
			
			// down
			for(int x=i+1; x<=i+current; x++) {
				if(x<n) {
					if(dist[x][j]==-1 || dist[x][j]>dist[i][j]+1) {
						dist[x][j]=dist[i][j]+1;
					}
				}
			}
			
			// right
			for(int y=j+1; y<=j+current; y++) {
				if(y<m) {
					if(dist[i][y]==-1 || dist[i][y]>dist[i][j]+1) {
						dist[i][y]=dist[i][j]+1;
					}
				}
			}
		}
	}
	
	cout<<dist[n-1][m-1];

	return 0;
}
