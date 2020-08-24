#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int INF=1e9+1;
const int MAX=1e3+1;

int N,M;
vector<int> a[MAX];
int adj[MAX][MAX];
int d[MAX], b[MAX];

int dijkstra() {
	fill(d,d+MAX,INF);
	
	priority_queue<pi> q;
	q.push({0,1});
	d[1]=0;
	b[1]=-1;
	
	while(!q.empty()) {
		int cost=-q.top().first;
		int x=q.top().second;
		q.pop();
		
		if(d[x]<cost) continue;
		for(auto& y : a[x]) {
			int weight=cost+adj[x][y];
			if(d[y]>weight) {
				d[y]=weight;
				b[y]=x;
				q.push({-weight,y});
			}
		}
	}
	
	return (d[N]==INF) ? -1 : d[N];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N>>M;
	for(int i=0; i<M; i++) {
		int u,v,c;
		cin>>u>>v>>c;
		
		adj[u][v]=adj[v][u]=c;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	// find edges of shortest path from 1 to N
	int min_time=dijkstra();
	
	vector<pi> edges;
	int current=N;
	while(b[current]!=-1) {
		edges.push_back({b[current], current});
		current=b[current];
	}
	
	int ans=0;
	for(auto& p : edges) {
		int u=p.first;
		int v=p.second;
		int c=adj[u][v];

		adj[u][v]=adj[v][u]=INF;
		
		int delayed=dijkstra();
		if(delayed==-1) {
			ans=-1;
			break;
		} else {
			ans=max(ans,delayed-min_time);
		}
		
		adj[u][v]=adj[v][u]=c;
	}
	cout<<ans;
	
	return 0;
}
