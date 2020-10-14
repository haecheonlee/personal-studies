/* reference: http://www.usaco.org/current/data/sol_distant.html */

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=31;

int N,A,B;
char a[MAX][MAX];
int d[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int dijkstra(int sx, int sy) {
	memset(d, 0x3f, sizeof(d));
	priority_queue<pair<int,pi>> q;
	q.push({0,{sx,sy}});
	d[sx][sy]=0;
	
	int ans=0;
	while(!q.empty()) {
		int c=-q.top().first;
		int x=q.top().second.first;
		int y=q.top().second.second;
		q.pop();
	
		ans=max(ans, d[x][y]);	
		if(d[x][y]<c) continue;
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(1<=nx && nx<=N && 1<=ny && ny<=N) {
				int nc=(a[x][y]==a[nx][ny] ? A : B) + c;
				if(d[nx][ny]>nc) {
					d[nx][ny]=nc;
					q.push({-nc, {nx,ny}});
				}
			}
		}
	}

	return ans;
}

int main() {
	cin>>N>>A>>B;

	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) cin>>a[i][j];
	}
	
	int ans=0;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) ans=max(ans, dijkstra(i,j));
	}
	cout<<ans;
	
	return 0;
}
