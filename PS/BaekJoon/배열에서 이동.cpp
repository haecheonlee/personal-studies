#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;
using PI=pair<int,int>;

int n;
int a[101][101];
bool c[101][101];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

bool bfs(int mn, int mx) {
	if(mn>a[0][0] || mx<a[0][0]) return false;
	memset(c,false,sizeof(c));
	
	queue<PI> q;
	q.push(make_pair(0,0));
	while(!q.empty()) {
		int x,y;
		tie(x,y)=q.front();
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=dx[k]+x;
			int ny=dy[k]+y;
			
			if(0<=nx && nx<n && 0<=ny && ny<n) {
				if(c[nx][ny]==false) {
					if(mn<=a[nx][ny] && a[nx][ny]<=mx) {
						q.push(make_pair(nx,ny));
						c[nx][ny]=true;
					}
				}
			}
		}
	}
	
	return c[n-1][n-1];
}

bool go(int diff) {
	for(int mn=0; mn+diff<=200; mn++) {
		if(bfs(mn, mn+diff)) return true;
	}
	
	return false;
}

int main() {
	cin>>n;

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) cin>>a[i][j];
	}
	
	int left=0;
	int right=200;
	int ans=200;
	
	while(left<=right) {
		int mid=(left+right)/2;
		
		if(go(mid)) {
			right=mid-1;
			ans=min(ans, mid);
		} else {
			left=mid+1;
		}
	}
	cout<<ans;
	
	return 0;
}

/*
INPUT:
5
1 1 3 6 8
1 2 2 5 5
4 4 0 3 3
8 0 2 3 4
4 3 0 2 1

OUTPUT:
2
*/
