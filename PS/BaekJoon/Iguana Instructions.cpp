#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;
using tpl=tuple<int,int,int>;

const int MAX=1e2;

int d[MAX][MAX][4];	// 0: N, 1: E, 2: S, 3: W
string s[MAX];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

inline int getOpposite(int dir) {
	if(dir==0) return 2;
	else if(dir==1) return 3;
	else if(dir==2) return 0;
	else if(dir==3) return 1;
}

int main() {
	int N;
	cin>>N;
	
	memset(d,-1,sizeof(d));
	for(int i=0; i<N; i++) cin>>s[i];
	
	queue<tpl> q;
	q.push({0,0,2}); q.push({0,0,1});
	d[0][0][1]=d[0][0][2]=1;
	
	while(!q.empty()) {
		int x=get<0>(q.front());
		int y=get<1>(q.front());
		int dir=get<2>(q.front());
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<N && 0<=ny && ny<N) {
				if(s[nx][ny]=='#') continue;
				
				if(k==dir) {
					if(d[nx][ny][k]==-1 || d[nx][ny][k]>d[x][y][dir]) {
						d[nx][ny][k]=d[x][y][dir];
						q.push({nx,ny,k});
					}
				} else {
					if(d[nx][ny][k]==-1 || d[nx][ny][k]>d[x][y][dir]+1) {
						d[nx][ny][k]=d[x][y][dir]+1;
						q.push({nx,ny,k});
					}
				}
			}
		}
	}
	
	int ans=-1;
	for(int k=0; k<4; k++) {
		int ret=d[N-1][N-1][k];

		if(ret==-1) continue;
		if(ans==-1 || ans>ret) ans=ret;
	}
	cout<<ans;
	
	return 0;
}
