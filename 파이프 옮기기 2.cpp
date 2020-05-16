#include <iostream>
#include <cstring>

using namespace std;

// 0-horizontal, 1-vertical, 2-diagonal
long long d[35][35][3];
int a[35][35];
int n;

long long go(int x, int y, int dir) {
	if(x==n-1 && y==n-1) return 1;
	
	long long &ans=d[x][y][dir];
	if(ans!=-1) return ans;
	ans=0;
	
	if(dir==0) {
		// to horizontal
		if(y+1<n && a[x][y+1]==0) ans+=go(x,y+1,0);
		// to diagonal
		if(x+1<n && y+1<n && a[x+1][y]==0 && a[x][y+1]==0 && a[x+1][y+1]==0) ans+=go(x+1,y+1,2);
	} else if(dir==1) {
		// to vertical
		if(x+1<n && a[x+1][y]==0) ans+=go(x+1,y,1);
		// to diagonal
		if(x+1<n && y+1<n && a[x+1][y]==0 && a[x][y+1]==0 && a[x+1][y+1]==0) ans+=go(x+1,y+1,2);
	} else if(dir==2) {
		// to horizontal
		if(y+1<n && a[x][y+1]==0) ans+=go(x,y+1,0);
		// to vertical
		if(x+1<n && a[x+1][y]==0) ans+=go(x+1,y,1);
		// to diagonal
		if(x+1<n && y+1<n && a[x+1][y]==0 && a[x][y+1]==0 && a[x+1][y+1]==0) ans+=go(x+1,y+1,2);
	}
	
	return ans;
}

int main() {
	cin>>n;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) cin>>a[i][j];
	}

	memset(d,-1,sizeof(d));
	cout<<go(0,1,0);

	return 0;
}
