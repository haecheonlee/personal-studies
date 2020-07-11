#include <iostream>
#include <queue>

using namespace std;
using pi=pair<int,int>;

int a[100][100];
int g[100][100];
int d[100][100];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
	int N;
	cin>>N;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) cin>>a[i][j];
	}
	
	int cnt=0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(a[i][j]==1 && g[i][j]==0) {
				g[i][j]=++cnt;
				
				queue<pi> q;
				q.push(make_pair(i,j));
				while(!q.empty()) {
					int x=q.front().first;
					int y=q.front().second;
					q.pop();
					
					for(int k=0; k<4; k++) {
						int nx=x+dx[k];
						int ny=y+dy[k];
						
						if(0<=nx && nx<N && 0<=ny && ny<N) {
							if(a[nx][ny]==1 && g[nx][ny]==0) {
								g[nx][ny]=cnt;
								q.push(make_pair(nx,ny));
							}
						}
					}
				}
			}
		}
	}
	
	queue<pi> q;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			d[i][j]=-1;
			
			if(a[i][j]==1) {
				q.push(make_pair(i,j));
				d[i][j]=0;
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
			
			if(0<=nx && nx<N && 0<=ny && ny<N) {
				if(d[nx][ny]==-1) {
					d[nx][ny]=d[x][y]+1;
					g[nx][ny]=g[x][y];
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
	
	int ans=-1;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			for(int k=0; k<4; k++) {
				int x=i+dx[k];
				int y=j+dy[k];
				
				if(0<=x && x<N && 0<=y && y<N) {
					if(g[i][j]!=g[x][y]) {
						if(ans==-1 || ans>d[i][j]+d[x][y]) ans=d[i][j]+d[x][y];
					}
				}
			}
		}
	}
	cout<<ans;
	
	return 0;	
}
