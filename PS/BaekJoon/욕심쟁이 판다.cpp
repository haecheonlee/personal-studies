#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n;
int a[501][501];
int d[501][501];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

int go(int x, int y) {
	if(d[x][y]!=0) return d[x][y];

	d[x][y]=1;
	for(int k=0; k<4; k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		
		if(0<=nx && nx<n && 0<=ny && ny<n) {
			if(a[x][y]<a[nx][ny]) {
				d[x][y]=max(d[x][y], go(nx,ny)+1);
			}
		}
	}
	
	return d[x][y];
}

int main() {
	cin>>n;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) cin>>a[i][j];
	}

	int ans=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			ans=max(ans,go(i,j));
		}
	}
	cout<<ans;

	return 0;
}
