#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
using PI=pair<int,int>;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
	int n,index=1;
	while(cin>>n) {
		if(n==0) break;
		
		int a[n][n];
		int dist[n][n];

		memset(dist, -1, sizeof(dist));
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) cin>>a[i][j];
		}
		
		queue<PI> q;
		q.push(make_pair(0,0));
		dist[0][0]=a[0][0];

		while(!q.empty()) {
			int x=q.front().first;
			int y=q.front().second;
			q.pop();
			
			for(int k=0; k<4; k++) {
				int nx=dx[k]+x;
				int ny=dy[k]+y;
				
				if(0<=nx && nx<n && 0<=ny && ny<n) {
					if(dist[nx][ny]==-1) {
						dist[nx][ny]=dist[x][y]+a[nx][ny];
						q.push(make_pair(nx,ny));
					} else {
						int next=dist[x][y]+a[nx][ny];
						if(dist[nx][ny]>next) {
							dist[nx][ny]=next;
							q.push(make_pair(nx,ny));
						}
					}
				}
			}
		}
		
		cout<<"Problem "<<index++<<": ";
		cout<<dist[n-1][n-1]<<'\n';
	}

	return 0;
}
