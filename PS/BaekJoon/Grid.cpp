#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

int N,M;
int board[501][501];
int d[501][501];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
	memset(d,-1,sizeof(d));

	cin>>N>>M;

	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			scanf("%1d", &board[i][j]);
		}
	}
	
	queue<pi> q;
	q.push(make_pair(1,1));
	d[1][1]=0;

	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx,ny;
			
			if(dx[k]==0) nx=x;
			else if(dx[k]==1) nx=x+board[x][y];
			else if(dx[k]==-1) nx=x-board[x][y];

			if(dy[k]==0) ny=y;
			else if(dy[k]==1) ny=y+board[x][y];
			else if(dy[k]==-1) ny=y-board[x][y];

			if(1<=nx && nx<=N && 1<=ny && ny<=M) {
				if(d[nx][ny]==-1) {
					d[nx][ny]=d[x][y]+1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}

	if(d[N][M]==-1) cout<<"IMPOSSIBLE";
	else cout<<d[N][M];
	
	return 0;
}
