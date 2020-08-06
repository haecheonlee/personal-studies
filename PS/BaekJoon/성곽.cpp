/* reference: baekjoon/codeplus */

#include <iostream>
#include <queue>

using namespace std;
using pi=pair<int,int>;

int N,M;
int a[50][50];
int d[50][50];
int room[50*50];
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};

int bfs(int x, int y, int rooms) {
	queue<pi> q;
	q.push(make_pair(x,y));
	d[x][y]=rooms;
	int cnt=0;
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		cnt+=1;
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<N && 0<=ny && ny<M) {
				if(d[nx][ny]!=0) continue;
				if(a[x][y] & (1<<k)) continue;
				
				d[nx][ny]=rooms;
				q.push(make_pair(nx,ny));
			}
		}
	}
	
	return cnt;
}

int main() {
	cin>>M>>N;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) cin>>a[i][j];
	}
	
	int rooms=0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(d[i][j]==0) {
				rooms+=1;
				room[rooms]=bfs(i,j,rooms);
			}
		}
	}
	
	// answer 1
	cout<<rooms<<'\n';
	
	// answer 2
	int ans=0;
	for(int i=1; i<=rooms; i++) ans=max(ans, room[i]);
	cout<<ans<<'\n';
	
	// answer 3
	ans=0;
	for(int x=0; x<N; x++) {
		for(int y=0; y<M; y++) {
			for(int k=0; k<4; k++) {
				int nx=x+dx[k];
				int ny=y+dy[k];
				
				if(0<=nx && nx<N && 0<=ny && ny<M) {
					if(d[nx][ny]==d[x][y]) continue;
					if(a[x][y] & (1<<k)) {
						ans=max(ans, room[d[x][y]]+room[d[nx][ny]]);
					}
				}
			}
		}
	}
	cout<<ans;
	
	return 0;
}
