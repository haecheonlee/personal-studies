#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e2+1;
const int INF=1e9;

int N,M;
char a[MAX][MAX];
int d[3][MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void bfs(int sx, int sy, int i) {
	queue<pi> q;
	q.push({sx, sy});
	d[i][sx][sy]=0;
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(1<=nx && nx<=N && 1<=ny && ny<=M) {
				if(a[nx][ny]=='1') continue;
				if(d[i][nx][ny]==-1) {
					d[i][nx][ny]=d[i][x][y]+1;
					q.push({nx,ny});
				}
			}
		}
	}
}

int main() {
	cin>>N>>M;
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) cin>>a[i][j];
	}
	
	memset(d, -1, sizeof(d));
	for(int k=0; k<3; k++) {
		int x,y;
		cin>>x>>y;
		bfs(x,y,k);
	}

	int ans=INF, cnt=0;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			int taken=0;
			bool is_possible=true;
			for(int k=0; k<3; k++) {
				if(d[k][i][j]==-1) {
					is_possible=false;
					break;
				} else {
					taken=max(taken, d[k][i][j]);
				}
			}
			
			if(is_possible) {
				if(ans==taken) {
					cnt++;
				} else if(ans>taken) {
					ans=taken;
					cnt=1;
				}
			}
		}
	}
	
	if(ans==INF) cout<<-1;
	else cout<<ans<<'\n'<<cnt;

	return 0;
}
