#include <iostream>
#include <algorithm>

using namespace std;

int board[30][30];
int board2[30][30];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int result[25*25];
int n;

void dfs(int x, int y, int total) {
	board2[x][y]=total;
	for(int k=0; k<4; k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		
		if(0<=nx && nx<n && 0<=ny && ny<n) {
			if(board[nx][ny]==1 && board2[nx][ny]==0) {
				dfs(nx,ny,total);
			}
		}
	}
} 

int main() {
	cin>>n;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			char c;
			cin>>c;
	
			board[i][j]=c-48;
		}
	}
	
	int total=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(board[i][j]==1 && board2[i][j]==0) {
				dfs(i,j,++total);	
			}
		}	
	}
	
	cout<<total<<'\n';
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			result[board2[i][j]]+=1;
		}
	}

	sort(result+1, result+total+1);
	for(int i=1; i<=total; i++) {
		cout<<result[i]<<'\n';
	}

	return 0;
}

/*
boj.kr/2667

INPUT:
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000

OUTPUT:
3
7
8
9
*/
