#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int board[300][300];
int dist[300][300];
int dx[]={-2,-2,-1,-1,1,1,2,2};
int dy[]={-1,1,-2,2,-2,2,-1,1};
int l;

void bfs(int x, int y, int count) {
	queue<pair<int,int>> q;
	q.push(make_pair(x,y));
	dist[x][y]=0;

	while(!q.empty()) {
		int cur_x=q.front().first;
		int cur_y=q.front().second;
		q.pop();
		
		for(int k=0; k<8; k++) {
			int nx=cur_x+dx[k];
			int ny=cur_y+dy[k];
			
			if(0<=nx && nx<l && 0<=ny && ny<l) {
				if(dist[nx][ny]==-1) {
					dist[nx][ny]=dist[cur_x][cur_y]+1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
}

int main() {
	int t,p1,p2,t1,t2;
	cin>>t;
	
	while(t--) {
		cin>>l;
		cin>>p1>>p2;
		cin>>t1>>t2;
		
		for(int i=0; i<l ;i++) {
			for(int j=0; j<l; j++) {
				dist[i][j]=-1;
			}
		}
		
		bfs(p1,p2,0);
		cout<<dist[t1][t2]<<'\n';
	}
	
	return 0;
}

/*
boj.kr/7562

INPUT:
3
8
0 0
7 0
100
0 0
30 50
10
1 1
1 1

OUTPUT:
5
28
0
*/
