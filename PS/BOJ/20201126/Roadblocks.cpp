#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 5e3 + 1;

int N, M;
vector<pii> G[MAX], E[MAX];
vector<pair<pii,int>> edges;
int d[MAX];

int dijkstra() {
	memset(d, 0x3f, sizeof(d));
	priority_queue<pii> pq;
	pq.push({0, 1});
	d[1] = 0;
	
	while(!pq.empty()) {
		int now = pq.top().second;
		int c = -pq.top().first;
		pq.pop();
		
		if(d[now] < c) continue;
		for(auto& v : G[now]) {
			int nxt = v.first;
			int nc = c + v.second;
			
			if(d[nxt] > nc) {
				E[nxt].clear(); E[nxt].push_back({now, v.second});
				d[nxt] = nc;
				pq.push({-nc, nxt});
			} else if(d[nxt] == nc) {
				E[nxt].push_back({now, v.second});
			}
		}
	}
	
	return d[N];
}

int dijkstra2(int a, int b, int cost) {
	memset(d, 0x3f, sizeof(d));
	priority_queue<pii> pq;
	pq.push({0, 1});
	d[1] = 0;
	
	while(!pq.empty()) {
		int now = pq.top().second;
		int c = -pq.top().first;
		pq.pop();
		
		if(d[now] < c) continue;
		for(auto& v : G[now]) {
			int nxt = v.first;
			int nc = c + v.second;
			
			if(((a == now && b == nxt) || (a == nxt && b == now)) && cost == v.second) continue;
			if(d[nxt] > nc) {
				d[nxt] = nc;
				pq.push({-nc, nxt});
			}
		}
	}
	
	return d[N];
}

void getEdges(int now) {
	if(E[now].empty()) return;
	for(auto& v : E[now]) {
		int prev = v.first, c = v.second;
		edges.push_back({{prev, now}, c});
		getEdges(prev);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> M;
	
	for(int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		
		G[u].push_back({v, c});
		G[v].push_back({u, c});
	}
	
	int spd = dijkstra();
	getEdges(N);
	
	int ans = 1e9;
	for(auto& e : edges) {
		int u = e.first.first, v = e.first.second;
		int c = e.second;
		
		ans = min(ans, spd + (c * 2));
		
		int dist = dijkstra2(u, v, c);
		if(dist == spd) continue;
		ans = min(ans, dist);
	}
	cout << ans;
		
	return 0;
}
