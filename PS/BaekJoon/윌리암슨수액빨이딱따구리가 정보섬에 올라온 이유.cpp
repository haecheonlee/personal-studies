#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=3e3;

char s[MAX][MAX];
int d[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin>>N>>M;
	
	int sx,sy;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin>>s[i][j];
			
			if(s[i][j]=='2') {
				sx=i;
				sy=j;
			}
		}
	}
	
	memset(d,-1,sizeof(d));
	queue<pi> q;
	q.push({sx,sy});
	d[sx][sy]=0;
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<N && 0<=ny && ny<M) {
				if(s[nx][ny]=='1') continue;
				if(d[nx][ny]==-1) {
					d[nx][ny]=d[x][y]+1;
					q.push({nx,ny});
				}
			}
		}
	}
	
	int ans=-1;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(d[i][j]==-1) continue;
			if(s[i][j]=='3' || s[i][j]=='4' || s[i][j]=='5') {
				if(ans==-1 || ans>d[i][j]) ans=d[i][j];
			}
		}
	}
	
	if(ans==-1) cout<<"NIE";
	else cout<<"TAK"<<'\n'<<ans;
	
	return 0;
}
