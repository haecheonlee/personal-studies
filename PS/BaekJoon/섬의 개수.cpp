#include <iostream>
#include <vector>

using namespace std;

int board[50][50];
int dist[50][50];
int result[50*50];
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,-1,1};
int w,h;

void dfs(int x, int y, int cnt) {
	dist[x][y]=cnt;
	for(int k=0; k<8; k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		
		if(0<=nx && nx<h && 0<=ny && ny<w) {
			if(board[nx][ny]==1 && dist[nx][ny]==0) {
				dfs(nx,ny,cnt);
			}
		}
	}
}

int main() {
	while(1) {
		cin>>w>>h;
		if(w==0 && h==0) break;
	
		for(int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				cin>>board[i][j];
				dist[i][j]=0;
			}
		}
	
		int count=0;
		for(int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				if(board[i][j]==1 && dist[i][j]==0) {
					dfs(i,j,++count);
				}
			}
		}
		
		cout<<count<<'\n';
	}

	return 0;
}

/*
boj.kr/4963

INPUT:
1 1
0
2 2
0 1
1 0
3 2
1 1 1
1 1 1
5 4
1 0 1 0 0
1 0 0 0 0
1 0 1 0 1
1 0 0 1 0
5 4
1 1 1 0 1
1 0 1 0 1
1 0 1 0 1
1 0 1 1 1
5 5
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0

OUTPUT:
0
1
1
3
1
9
*/
