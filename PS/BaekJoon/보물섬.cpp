#include <iostream>
#include <queue>

using namespace std;

char area[50][50];
int dist[50][50];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m;
int longest=0;

void reset() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(area[i][j]=='L') dist[i][j]=0;
			else dist[i][j]=-1;
		}
	}
}

int countDistance() {
	int largest_num=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(dist[i][j]>largest_num) largest_num=dist[i][j];
		}
	}
	return largest_num;
}

void bfs(int x, int y, int count) {
	queue<pair<int,int>> q;
	q.push(make_pair(x,y));
	dist[x][y]=count;
	
	while(!q.empty()) {
		int current_x=q.front().first;
		int current_y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=current_x+dx[k];
			int ny=current_y+dy[k];
			
			if(0<=nx && nx<n && 0<=ny && ny<m) {
				if(area[nx][ny]=='L' && dist[nx][ny]==0) {
					q.push(make_pair(nx,ny));
					dist[nx][ny]=dist[current_x][current_y]+1;
				}
			}
		}
	}
}

int main() {
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin>>area[i][j];
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			reset();
			if(area[i][j]=='L') {
				bfs(i,j,0);
				longest=max(longest, countDistance());
			}
		}
	}
	
	cout<<longest;
	
	return 0;
}

/*
boj.kr/2589

INPUT:
5 7
WLLWWWL
LLLWLLL
LWLWLWW
LWLWLLL
WLLWLWW

OUTPUT:
8
*/
