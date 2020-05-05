#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int a[1001][1001];
int d[1001][1001][11];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
	int n,m,k;
	cin>>n>>m>>k;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) scanf("%1d", &a[i][j]);
	}
	
	queue<tuple<int,int,int>> q;
	q.push(make_tuple(0,0,0));
	d[0][0][0]=1;
	
	while(!q.empty()) {
		int x,y,z;
		tie(x,y,z)=q.front();
		q.pop();
		
		for(int i=0; i<4; i++) {
			int nx=dx[i]+x;
			int ny=dy[i]+y;
			
			if(0<=nx && nx<n && 0<=ny && ny<m) {
				if(a[nx][ny]==0 && d[nx][ny][z]==0) {
					d[nx][ny][z]=d[x][y][z]+1;
					q.push(make_tuple(nx,ny,z));
				}
				
				if(z+1<=k && a[nx][ny]==1 && d[nx][ny][z+1]==0) {
					d[nx][ny][z+1]=d[x][y][z]+1;
					q.push(make_tuple(nx,ny,z+1));
				}
			}
		}
	}
	
	int ans=-1;
	for(int i=0; i<=k; i++) {
		if(d[n-1][m-1][i]==0) continue;
		if(ans==-1 || ans>d[n-1][m-1][i]) ans=d[n-1][m-1][i];
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
