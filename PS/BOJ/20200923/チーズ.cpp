#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e3;

int N,M,K;
char a[MAX][MAX];
pi p[10];
int d[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int bfs(int x, int next) {
	memset(d, -1, sizeof(d));
	
	queue<pi> q;
	q.push({p[x].first, p[x].second});
	d[p[x].first][p[x].second]=0;
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		if((a[x][y]-'0')==next) return d[x][y];
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<N && 0<=ny && ny<M) {
				if(a[nx][ny]=='X') continue;
				if(d[nx][ny]==-1) {
					d[nx][ny]=d[x][y]+1;
					q.push({nx,ny});
				}
			}
		}
	}
	
	return 0;
}

int main() {
	cin>>N>>M>>K;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin>>a[i][j];
			
			if(a[i][j]=='S') {
				p[0].first=i, p[0].second=j;
			}
			else if(a[i][j]>='1' && a[i][j]<='9') {
				int num=a[i][j]-'0';
				p[num].first=i, p[num].second=j;
			}
		}
	}
	
	int ans=0;
	for(int i=0; i<K; i++) ans+=bfs(i,i+1);
	cout<<ans;
	
	return 0;
}
