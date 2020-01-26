#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int box[1001][1001];
int dist[1001][1001];
int m,n;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
	cin>>m>>n;
	
	queue<pair<int,int>> q;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin>>box[i][j];
			dist[i][j]=-1;
			
			if(box[i][j]==1) { 
				q.push(make_pair(i,j));
				dist[i][j]=0;
			}
		}
	}
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<n && 0<=ny && ny<m) {
				if(box[nx][ny]==0 && dist[nx][ny]==-1) {
					dist[nx][ny]=dist[x][y]+1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
	
	int result=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(result<dist[i][j]) result=dist[i][j];
			if(box[i][j]==0 && dist[i][j]==-1) {
				result=-1;
				break;
			}
		}
		
		if(result==-1) break;
	}
	
	cout<<result;
	
	return 0;
}

/*
boj.kr/7576

INPUT:
6 4
1 -1 0 0 0 0
0 -1 0 0 0 0
0 0 0 0 -1 0
0 0 0 0 -1 1

OUTPUT:
6
*/
