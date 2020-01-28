#include <iostream>

using namespace std;

int city[100][100];
int dist[100][100];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n;

void reset(){ 
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			dist[i][j]=0;
		}
	}
}

void dfs(int x, int y, int count, int height) {
	dist[x][y]=count;
	
	for(int k=0; k<4; k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		
		if(0<=nx && nx<n && 0<=ny && ny<n) {
			if(dist[nx][ny]==0 && city[nx][ny]>height) {
				dfs(nx,ny,count,height);
			}
		}
	}
}

int main() {
	cin>>n;
	
	int highest=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin>>city[i][j];
			highest=max(highest,city[i][j]);
		}
	}
	
	int safe=0;
	for(int height=0; height<=highest; height++) {
		int count=0;
		reset();
		for(int x=0; x<n; x++) {
			for(int y=0; y<n; y++) {
				if(city[x][y]>height && dist[x][y]==0) {
					dfs(x,y,++count,height);
				}
			}
		}
		safe=max(safe,count);
	}

	cout<<safe;

	return 0;
}

/*
boj.kr/2468

INPUT:
5
6 8 2 6 2
3 2 3 4 6
6 7 3 3 2
7 2 5 3 6
8 9 5 2 7

OUTPUT:
5
*/
