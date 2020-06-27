#include <iostream>
#include <cstring>

using namespace std;

int N,M;
int a[501][501];
int d[501][501];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

int go(int x, int y) {
	if(x==N-1 && y==M-1) return 1;
	
	int &ans=d[x][y];
	if(ans!=-1) return ans;
	
	ans=0;
	for(int k=0; k<4; k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		
		if(0<=nx && nx<N && 0<=ny && ny<M) {
			if(a[x][y]>a[nx][ny]) ans+=go(nx,ny);
		}
	}
	
	return ans;
}

int main() {
	cin>>N>>M;

	memset(d,-1,sizeof(d));	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) cin>>a[i][j];
	}
	
	cout<<go(0,0);

	return 0;
}
