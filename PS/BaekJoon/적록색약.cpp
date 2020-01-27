#include <iostream>

using namespace std;

char grid[100][100];
char grid2[100][100];
int dist[100][100];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int n;

void dfs(int x, int y, char color, int count) {
	grid[x][y]='X';
	dist[x][y]=count;
	for(int k=0; k<4; k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		
		if(0<=nx && nx<n && 0<=ny && ny<n) {
			if(grid[nx][ny]==color && dist[nx][ny]==0) {
				dfs(nx,ny,color,count);
			}
		}
	}
}

int main() {
	cin>>n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin>>grid[i][j];
			
			if(grid[i][j]=='G') grid2[i][j]='R';
			else grid2[i][j]=grid[i][j];
		}
	}
	
	int count=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(grid[i][j]!='X' && dist[i][j]==0) {
				char color=grid[i][j];
				dfs(i,j,color,++count);
			}
		}
	}
	cout<<count<<" ";
	
	count=0;
	for(int i=0;i<n; i++) {
		for(int j=0; j<n; j++) {
			grid[i][j]=grid2[i][j];
			dist[i][j]=0;
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(grid[i][j]!='X' && dist[i][j]==0) {
				char color=grid[i][j];
				dfs(i,j,color,++count);
			}
		}
	}
	
	cout<<count;

	return 0;
}

/*
boj.kr/10026

INPUT:
5
RRRBB
GGBBB
BBBRR
BBRRR
RRRRR

OUTPUT:
4 3
*/
