#include <iostream>
#include <queue>

using namespace std;

int n;
int d[201][201];
int a[201][201];
int dx[]={-2,-2,0,0,2,2};
int dy[]={-1,1,-2,2,-1,1};

int main() {
	cin>>n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) d[i][j]=-1;
	}
	int start_x,start_y,end_x,end_y;
	cin>>start_x>>start_y>>end_x>>end_y;
	
	queue<pair<int,int>> q;
	q.push({start_x,start_y});
	d[start_x][start_y]=0;
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<6; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<n && 0<=ny && ny<n) {
				if(d[nx][ny]==-1) {
					d[nx][ny]=d[x][y]+1;
					q.push({nx,ny});
				}
			}
		}
	}

	cout<<d[end_x][end_y];

	return 0;
}

/*
boj.kr/16948

INPUT:
6
5 1 0 5

OUTPUT:
-1
*/
