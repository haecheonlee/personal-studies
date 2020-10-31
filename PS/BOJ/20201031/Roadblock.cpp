#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pii = pair<int,int>;

const int MAX = 1e2 + 1;

int N,M;
vector<int> a[MAX];
int adj[MAX][MAX];
vector<int> p[MAX];
vector<pii> edges;
int d[MAX];

void get(int y) {
	for(auto& x : p[y]) {
		edges.push_back({x,y});
		get(x);
	}
}

int dijkstra() {
	memset(d, 0x3f, sizeof(d));
	
    priority_queue<pii> q;
	q.push({0,1});
	d[1] = 0;
	
	while(!q.empty()) {
		int c = -q.top().first;
		int x = q.top().second;
		q.pop();
		
		if(d[x] < c) continue;
		for(auto& y : a[x]) {
			int nc = c + adj[x][y];
			
			if(d[y] > nc) {
				p[y].clear();
				p[y].push_back(x);
				d[y] = nc;
				q.push({-nc, y});
			} else if(d[y] == nc) {
				p[y].push_back(x);
			}
		}
	}
	    
	return d[N];
}

int main() {
	cin>>N>>M;
	
	for(int i = 0; i < M; i++) {
		int u,v,c;
		cin>>u>>v>>c;
		
		a[u].push_back(v); a[v].push_back(u);
		adj[u][v]=adj[v][u]=c;
	}
	
    int shortest = dijkstra();
    
    get(N);

	int ans = 0;
	for(auto& e : edges) {
		int x = e.first, y = e.second;
        adj[x][y]=adj[y][x]*=2;
		ans = max(ans, dijkstra() - shortest);
		adj[x][y]=adj[y][x]/=2;
	}
	cout<<ans;

	return 0;
}
