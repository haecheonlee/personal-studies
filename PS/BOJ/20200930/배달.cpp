#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;
using tpl=tuple<int,int,int,int>;

const int MAX=5e1;

char a[MAX][MAX];
int d[MAX][MAX][4][4];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

int main() {
	int N,M;
	cin>>N>>M;
	
	memset(d, -1, sizeof(d));
	queue<tpl> q;
	int sx, sy, ex1=-1, ey1=-1, ex2=-1, ey2=-1;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin>>a[i][j];
			
			if(a[i][j]=='S') {
				for(int k=0; k<4; k++) {
					d[i][j][k][0]=0;
					q.push({i,j,k,0});
				}
			} else if(a[i][j]=='C') {
				if(ex1==-1 && ey1==-1) ex1=i, ey1=j;
				else ex2=i, ey2=j;
			}
		}
	}
	
	int ans=-1;
	while(!q.empty()) {
		int x=get<0>(q.front());
		int y=get<1>(q.front());
		int dir=get<2>(q.front());
		int s=get<3>(q.front());
		q.pop();
		
		if(s==3) {
			ans=d[x][y][dir][s];
			break;
		}
		
		for(int k=0; k<4; k++) {
			if(dir==k) continue;
			
			int nx=x+dx[k];
			int ny=y+dy[k];
			if(0<=nx && nx<N && 0<=ny && ny<M) {
				if(a[nx][ny]!='#') {
					int ns=s;
					
					if(a[nx][ny]=='C') {
						if(nx==ex1 && ny==ey1) ns|=1;
						else ns|=2;
					}
					
					if(d[nx][ny][k][ns]==-1) {
						d[nx][ny][k][ns]=d[x][y][dir][s]+1;
						q.push({nx, ny, k, ns});
					}
				}
			}
		}
	}
	cout<<ans;

	return 0;
}
