#include <iostream>

using namespace std;

char board[50][50];
int dist[50][50];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
bool check[50][50];
int n,m;

bool go(int x, int y, int count, char color) {
	if(check[x][y]) return (count-dist[x][y])>=4;
	check[x][y]=true; dist[x][y]=count;
	
	for(int k=0; k<4; k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		
		if(0<=nx && nx<n && 0<=ny && ny<m) {
			if(board[nx][ny]==color) {
				if(go(nx, ny, count+1, color)) {
					return true;
				}
			}
		}
	}
	
	return false;
}

int main() {
	cin>>n>>m;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin>>board[i][j];
		}
	}
	
	bool result=false;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			result=(result || go(i,j,0,board[i][j]));
		}
	}
	
	if(result) cout<<"Yes";
	else cout<<"No";

	return 0;
}

/*
boj.kr/16929

INPUT:
7 6
AAAAAB
ABBBAB
ABAAAB
ABABBB
ABAAAB
ABBBAB
AAAAAB

OUTPUT:
Yes
*/
