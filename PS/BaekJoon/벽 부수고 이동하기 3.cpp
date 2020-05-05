#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int a[1001][1001];
int d[1001][1001][11][2];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
	int n,m,l;
	cin>>n>>m>>l;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) scanf("%1d", &a[i][j]);
	}

	queue<tuple<int,int,int,int>> q;
	q.push(make_tuple(0,0,0,0));
	d[0][0][0][0]=1;
	
	while(!q.empty()) {
		int x,y,z,state;
		tie(x,y,z,state)=q.front();
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=dx[k]+x;
			int ny=dy[k]+y;
			
			if(0<=nx && nx<n && 0<=ny && ny<m) {
				if(a[nx][ny]==0 && d[nx][ny][z][1-state]==0) {
					d[nx][ny][z][1-state]=d[x][y][z][state]+1;
					q.push(make_tuple(nx,ny,z,1-state));
				}
				
				if(state==0 && z+1<=l && a[nx][ny]==1 && d[nx][ny][z+1][1-state]==0) {
					d[nx][ny][z+1][1-state]=d[x][y][z][state]+1;
					q.push(make_tuple(nx,ny,z+1,1-state));
				}
			}
		}
		
		if(d[x][y][z][1-state]==0) {
			d[x][y][z][1-state]=d[x][y][z][state]+1;
			q.push(make_tuple(x,y,z,1-state));
		}
	}
	
	int ans=-1;
	for(int i=0; i<=l; i++) {
		for(int j=0; j<2; j++) {
			if(d[n-1][m-1][i][j]==0) continue;
			if(ans==-1 || ans>d[n-1][m-1][i][j]) ans=d[n-1][m-1][i][j];
		}
	}
	cout<<ans;

	return 0;
}

/*
INPUT:
6 4 1
0100
1110
1000
0000
0111
0000

OUTPUT:
15
*/
