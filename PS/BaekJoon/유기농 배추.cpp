#include <iostream>

using namespace std;

int ground[50][50];
int dist[50][50];
bool checked[50][50];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int m,n;

void reset() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			ground[i][j]=0;
			checked[i][j]=false;
			dist[i][j]=0;
		}
	}
}

void dfs(int x, int y, int index) {
	checked[x][y]=true;
	dist[x][y]=index;
	
	for(int k=0; k<4; k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		
		if(0<=nx && nx<n && 0<=ny && ny<m) {
			if(ground[nx][ny]==1 && checked[nx][ny]==false) {
				dfs(nx,ny,index);
			}
		}
	}
}

int main() {
	int t,k,x,y;
	cin>>t;
	
	while(t--) {
		cin>>m>>n>>k;
		reset();
		
		while(k--) {
			cin>>x>>y;
			ground[y][x]=1;
		}
		
		int index=0;
		int result=0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(!checked[i][j] && ground[i][j]==1) {
					dfs(i,j,++index);
				}
				result=max(result,dist[i][j]);
			}
		}
		
		cout<<result<<'\n';
	}

	return 0;
}

/*
boj.kr/1012

INPUT:
2
10 8 17
0 0
1 0
1 1
4 2
4 3
4 5
2 4
3 4
7 4
8 4
9 4
7 5
8 5
9 5
7 6
8 6
9 6
10 10 1
5 5

OUTPUT:
5
1
*/
