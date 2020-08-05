#include <iostream>
#include <queue>

using namespace std;
using pi=pair<int,int>;

int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

int main() {
	queue<pi> q;
	
	int N,M;
	cin>>N>>M;
	
	int a[N][M];
	int d[N][M];
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin>>a[i][j];
			d[i][j]=-1;
			if(a[i][j]==2) {
				d[i][j]=0;
				q.push(make_pair(i,j));
			}
		}
	}
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<N && 0<=ny && ny<M) {
				if(a[nx][ny]==1 && d[nx][ny]==-1) {
					d[nx][ny]=d[x][y]+1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}

	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(a[i][j]==0) cout<<0<<" ";
			else cout<<d[i][j]<<" ";
		}
		cout<<'\n';
	}

	return 0;
}
