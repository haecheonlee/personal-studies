#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pii=pair<int,int>;

const int MAX=1e3+1;

vector<int> a[MAX];
int adj[MAX][MAX];
int d[4][MAX];
int switches[3];
int p[MAX];
bool check[MAX][MAX];
pair<int,vector<pii>> ans;

void dfs(int y) {
	int x=p[y];
	if(x==-1) return;
	if(check[x][y]==false) {
		check[x][y]=check[y][x]=true;
		ans.first += adj[x][y];
		ans.second.push_back({x,y});
		dfs(x);
	}
}

void dijkstra(int idx, int start) {
	memset(d[idx], 0x3f, sizeof(d[idx]));

	priority_queue<pii> q;
	q.push({0,start});
	d[idx][start]=0;
	
	while(!q.empty()) {
		int c=-q.top().first;
		int x=q.top().second;
		q.pop();

		if(d[idx][x]<c) continue;
		for(auto& y: a[x]) {
			int nc=c+adj[x][y];

			if(d[idx][y]>nc) {
				d[idx][y]=nc;
				p[y]=x;
				q.push({-nc,y});
			}
		}
	}
}

int main() {
	int N,M;
	cin>>N>>M;

	for(int i=0; i<M; i++) {
		int u,v,c;
		cin>>u>>v>>c;

		a[u].push_back(v);
		a[v].push_back(u);
		adj[u][v]=adj[v][u]=c;
	}

	for(int i=0; i<3; i++) { cin>>switches[i]; dijkstra(i, switches[i]); }

	int node=-1, min_cost=1e9;
	for(int j=1; j<=N; j++) {
		int sum= d[0][j] + d[1][j] + d[2][j];
		if(min_cost > sum) node=j, min_cost=sum;
	}
	
	memset(p, -1, sizeof(p));
	dijkstra(3, node);
	for(int i=0; i<3; i++) dfs(switches[i]);
	cout<<ans.first<<' '<<ans.second.size()<<'\n';
	for(auto& e : ans.second) cout<<e.first<<' '<<e.second<<'\n';
}
