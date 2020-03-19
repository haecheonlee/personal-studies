#include <iostream>

using namespace std;

int n,m,k,r,c;
int d[101][101] {0};
bool visited[101][101];
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};

int dfs(int x, int y) {
	int cnt=1;

	visited[x][y]=true;
	d[x][y]=cnt;
	
	for(int k=0; k<4; k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		
		if(0<=nx && nx<n && 0<=ny && ny<m) {
			if(visited[nx][ny]==false && d[nx][ny]==0) {
				visited[nx][ny]=true;
				cnt+=dfs(nx,ny);
			}
		}
	}
	
	return cnt;
}

int main() {
	cin>>n>>m>>k;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) d[i][j]=-1;
	}
	
	for(int i=0; i<k; i++) {
		cin>>r>>c;
		d[r-1][c-1]=0;
	}
	
	int mx=-1;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(!visited[i][j] && d[i][j]==0) mx=max(mx,dfs(i,j));
		}
	}
	
	cout<<mx;

	return 0;
}

/*
INPUT:
3 4 5
3 2
2 2
3 1
2 3
1 1

OUTPUT:
4
*/
