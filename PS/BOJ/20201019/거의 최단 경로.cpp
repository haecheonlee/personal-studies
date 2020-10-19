#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pii=pair<int,int>;

const int MAX=5e2+1;
const int INF=1e9;

vector<pii> a[MAX];
vector<int> p[MAX];
int d[MAX];
bool check[MAX][MAX];

void dfs(int x) {
	for(auto& y : p[x]) {
		if(check[y][x]==false) {
			check[y][x]=true;
			dfs(y);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while(1) {
		int N,M;
		cin>>N>>M;
		
		if(N==0 && M==0) break;

		int S,D;
		cin>>S>>D;

		// reset
		memset(check, false, sizeof(check));
		for(int i=0; i<N; i++) {
			d[i]=INF;
			a[i].clear(), p[i].clear();
		}
	
		for(int i=0; i<M; i++) {
			int u,v,c;
			cin>>u>>v>>c;
			
			a[u].push_back({v,c});
		}
		
		// dijkstra starts
		priority_queue<pii> q;
		q.push({0,S});
		d[S]=0;
		
		while(!q.empty()) {
			int c=-q.top().first;
			int x=q.top().second;
			q.pop();
			
			if(d[x]<c) continue;
			for(auto& next : a[x]) {
				int y=next.first;
				int nc=d[x]+next.second;
				
				if(d[y]>nc) {
					p[y].clear();
					p[y].push_back(x);
					
					d[y]=nc;
					q.push({-nc, y});
				} else if(d[y]==nc) {
					p[y].push_back(x);
				}
			}
		}
			
		// check if shortest path exists
		if(d[D]==INF) {
			cout<<-1<<'\n';
			continue;	
		}
		
		// disable edges
		dfs(D);
		
		// dijkstra strats
		fill(d, d+N, INF);
		q.push({0,S});
		d[S]=0;
		
		while(!q.empty()) {
			int c=-q.top().first;
			int x=q.top().second;
			q.pop();
			
			if(d[x]<c) continue;
			for(auto& next : a[x]) {
				int y=next.first;
				int nc=d[x]+next.second;
				if(check[x][y]) continue;
				
				if(d[y]>nc) {
					d[y]=nc;
					q.push({-nc, y});
				}
			}
		}
		
		if(d[D]==INF) cout<<-1<<'\n';
		else cout<<d[D]<<'\n';
	}
	
	return 0;
}
