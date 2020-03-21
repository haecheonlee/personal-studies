#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> PI;

int n,m;
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
int a[51][51];
int d[51][51];

int main() {
	cin>>n>>m;
	
	queue<PI> q;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin>>a[i][j];
			
			d[i][j]=-1;
			if(a[i][j]==1) {
				q.push({i,j});
				d[i][j]=0;	
			}
		}
	}
	
	int ans=-1;
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<8; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<n && 0<=ny && ny<m) {
				if(a[nx][ny]==0 && d[nx][ny]==-1) {
					d[nx][ny]=d[x][y]+1;
					q.push({nx,ny});
					ans=max(d[nx][ny],ans);
				}
			}
		}
	}
	
	cout<<ans;
	
	return 0;
}

/*
INPUT:
5 4
0 0 1 0
0 0 0 0
1 0 0 0
0 0 0 0
0 0 0 1

OUTPUT:
2
*/
