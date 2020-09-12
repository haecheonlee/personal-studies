#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;
using tpl=tuple<int,int,int>;

const int MAX=1e3+1;

int a[MAX][MAX];
int d[MAX][MAX][2];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

int main() {
	int N,M;
	cin>>N>>M;
	
	memset(d, -1, sizeof(d));
	int sx,sy,ex,ey;
	cin>>sx>>sy>>ex>>ey;

	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) cin>>a[i][j];
	}
	
	queue<tpl> q;
	d[sx][sy][0]=0;
	q.push({sx,sy,0});
	
	while(!q.empty()) {
		int x=get<0>(q.front());
		int y=get<1>(q.front());
		int cost=get<2>(q.front());
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(1<=nx && nx<=N && 1<=ny && ny<=M) {
				if(a[nx][ny]==0) {
					if(d[nx][ny][cost]==-1) {
						d[nx][ny][cost]=d[x][y][cost]+1;
						q.push({nx,ny,cost});
					}
				}
				
				if(a[nx][ny]==1) {
					if(cost==0) {
						if(d[nx][ny][cost+1]==-1) {
							d[nx][ny][cost+1]=d[x][y][cost]+1;
							q.push({nx,ny,cost+1});
						}
					}
				}
			}
		}
	}
	
	int ans=-1;
	for(int i=0; i<2; i++) {
		int ret=d[ex][ey][i];
		
		if(ret==-1) continue;
		if(ans==-1 || ans>ret) ans=ret;
	}
	cout<<ans;
	
	return 0;
}
