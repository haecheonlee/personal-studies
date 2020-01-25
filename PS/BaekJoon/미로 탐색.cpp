#include <iostream>
#include <queue>

using namespace std;

int n,m;
int board[100][100];
bool check[100][100];
int dist[100][100];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
	cin>>n>>m;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			char c;
			cin>>c;
			
			board[i][j]=c-48;
		}
	}
	
	queue<pair<int,int>> q;
	q.push(make_pair(0,0));
	check[0][0]=true;
	dist[0][0]=1;
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<n && 0<=ny && ny<m) {
				if(check[nx][ny] == false && board[nx][ny]==1) {
					q.push(make_pair(nx,ny));
					dist[nx][ny]=dist[x][y]+1;
					check[nx][ny]=true;
				}
			}
		}
	}
	
	cout<<dist[n-1][m-1];

	return 0;
}

/*
boj.kr/2178

INPUT:
2 25
1011101110111011101110111
1110111011101110111011101

OUTPUT:
38
*/
