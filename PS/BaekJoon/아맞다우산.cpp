#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
using pi=pair<int,int>;

int N,M;
vector<pi> p;
int d[8][8];
int idx[51][51];
char a[51][51];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void bfs(int bx, int by, int i) {
	int dist[51][51];
	memset(dist,-1,sizeof(dist));
	
	queue<pi> q;
	q.push(make_pair(bx,by));
	dist[bx][by]=0;
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=dx[k]+x;
			int ny=dy[k]+y;
			
			if(0<=nx && nx<N && 0<=ny && ny<M) {
				if(a[nx][ny]=='#') continue;
				if(dist[nx][ny]==-1) {
					dist[nx][ny]=dist[x][y]+1;
					if(idx[nx][ny]!=-1) d[i][idx[nx][ny]]=dist[nx][ny];
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
}

int main() {
	cin>>M>>N;
	
	int sx,sy,ex,ey;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin>>a[i][j];
			
			if(a[i][j]=='X') {
				p.push_back(make_pair(i,j));
			}
			else if(a[i][j]=='S') {
				sx=i;
				sy=j;
			} else if(a[i][j]=='E') {
				ex=i;
				ey=j;
			}
		}
	}
	
	// indexing for each position
	memset(idx,-1,sizeof(idx));
	vector<int> pos;
	
	idx[sx][sy]=0;
	for(int i=0; i<p.size(); i++) {
		idx[p[i].first][p[i].second]=i+1;
		pos.push_back(i+1);	
	}
	idx[ex][ey]=p.size()+1;
	
	// min distance for every node
	bfs(sx,sy,idx[sx][sy]);
	for(int i=0; i<p.size(); i++) bfs(p[i].first, p[i].second, i+1);
	bfs(ex,ey,idx[ex][ey]);

	int ans=-1;
	if(pos.size()) {
		do {
			int sum=d[idx[sx][sy]][pos[0]];
			for(int i=1; i<pos.size(); i++) sum+=d[pos[i-1]][pos[i]];
			sum+=d[pos[pos.size()-1]][idx[ex][ey]];
			
			if(ans==-1 || ans>sum) ans=sum;
		} while(next_permutation(pos.begin(), pos.end()));
	} else {
		ans=d[0][1];
	}

	cout<<ans;
	
	return 0;
}
