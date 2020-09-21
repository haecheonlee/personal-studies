#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=50;

int N,M;
char a[MAX][MAX];
int d[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void bfs(int sx, int sy) {
	queue<pi> q;
	q.push({sx,sy});
	d[sx][sy]=0;
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<N && 0<=ny && ny<M) {
				if(a[nx][ny]=='X' && d[nx][ny]==-1) {
					d[nx][ny]=0;
					q.push({nx,ny});
				}
			}
		}
	}
}

int main() {
	cin>>N>>M;
	
	int sx=-1,sy=-1;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin>>a[i][j];
			
			if(a[i][j]=='X') {
				if(sx==-1 && sy==-1) sx=i,sy=j;
			}	
		}
	}
	
	memset(d, -1, sizeof(d));
	bfs(sx,sy);
	
	queue<pi> q;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(a[i][j]=='X' && d[i][j]==0) q.push({i,j});
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
				if(a[nx][ny]=='.') {
					if(d[nx][ny]==-1) {
						d[nx][ny]=d[x][y]+1;
						q.push({nx,ny});
					}
				} else if(a[nx][ny]=='X') {
					if(d[nx][ny]==-1) {
						cout<<d[x][y];
						return 0;	
					}
				}
			}
		}
	}
	
	return 0;
}
