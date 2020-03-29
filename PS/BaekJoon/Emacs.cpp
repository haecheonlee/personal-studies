#include <iostream>

using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

char picture[200][200];
int dist[200][200];

int n,m;

void dfs(int x, int y, int cnt) {
	for(int k=0; k<4; k++) {
		int nx=dx[k]+x;
		int ny=dy[k]+y;
		
		if(0<=nx && nx<n && 0<=ny && ny<m) {
			if(dist[nx][ny]==0) {
				dist[nx][ny]=cnt;
				dfs(nx,ny,cnt);
			}
		}
	}
}

int main() {
	cin>>n>>m;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin>>picture[i][j];
			
			if(picture[i][j]=='.') dist[i][j]=-1;
			else dist[i][j]=0;
		}
	}

	int cnt=1;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(dist[i][j]==0) {
				dist[i][j]=cnt;
				dfs(i,j,cnt++);
			}
		}
	}
	cout<<cnt-1;

	return 0;
}

/*
INPUT:
6 7
***....
***..**
.....**
.***.**
.***...
.***...

OUTPUT:
3
*/
