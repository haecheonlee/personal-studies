#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int h,w,l;
int dx[]={0,0,1,-1,-2,-1,1,2,2,1,-1,-2};
int dy[]={1,-1,0,0,1,2,2,1,-1,-2,-2,-1};
int cost[]={0,0,0,0,1,1,1,1,1,1,1,1};
int board[201][201];
int d[201][201][31];

int main() {
	cin>>l>>w>>h;
	
	for(int i=0; i<h; i++) {
		for(int j=0; j<w; j++) cin>>board[i][j];
	}

	memset(d,-1,sizeof(d));
	queue<tuple<int,int,int>> q;
	q.push({0,0,0});
	d[0][0][0]=0;
	
	while(!q.empty()) {
		int x,y,c;
		tie(x,y,c)=q.front();
		q.pop();
		
		for(int k=0; k<12; k++) {
            int nx=x+dx[k];
            int ny=y+dy[k];
            int nc=c+cost[k];
			
			if(0<=nx && nx<h && 0<=ny && ny<w) {
				if(board[nx][ny]==1) continue;
				if(nc<=l) {
					if(d[nx][ny][nc]==-1) {
						d[nx][ny][nc]=d[x][y][c]+1;
						q.push(make_tuple(nx,ny,nc));
					}		
				}
			}
		}
	}
	
	int ans=-1;
	for(int i=0; i<=l; i++) {
		if(d[h-1][w-1][i]==-1) continue;
		if(ans==-1 || ans>d[h-1][w-1][i]) ans=d[h-1][w-1][i];
	}
	cout<<ans;

	return 0;
}

/*
INPUT:
1
4 4
0 0 0 0
1 0 0 0
0 0 1 0
0 1 0 0

OUTPUT:
4
*/
