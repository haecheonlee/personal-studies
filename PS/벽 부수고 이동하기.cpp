#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int n,m;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
char a[1000][1000];
int d[1000][1000][2];

int main() {
	cin>>n>>m;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) cin>>a[i][j];
	}
	memset(d, -1, sizeof(d));
	queue<tuple<int,int,int>> q;
	q.push({0,0,0});
	d[0][0][0]=1;

	while(!q.empty()) {
		int x,y,c;
		tie(x,y,c)=q.front();
		q.pop();

		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx&&nx<n&&0<=ny&&ny<m) {
				if(a[nx][ny]=='0') {
					// if not wall
					if(d[nx][ny][c]==-1) {
						d[nx][ny][c]=d[x][y][c]+1;
						q.push(make_tuple(nx,ny,c));
					}
				} else {
					// if wall
					if(c==0) {
						// if not broken wall
						if(d[nx][ny][1]==-1) {
							d[nx][ny][1]=d[x][y][0]+1;
							q.push(make_tuple(nx,ny,1));
						}
					}
				}
			}
		}
	}
	
	int ans=-1;
	for(int i=0; i<2; i++) {
		if(d[n-1][m-1]==-1) continue;
		if(ans==-1 || ans>d[n-1][m-1][i]) {
			ans=d[n-1][m-1][i];
		}
	}
	cout<<ans;
	
	return 0;
}

/*
INPUT:
6 4
0100
1110
1000
0000
0111
0000

OUTPUT:
15
*/
