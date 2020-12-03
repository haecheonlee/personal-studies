#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define fi first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

const int MAX = 1e4 + 1;
const ll INF = 1e18;

int N, M, K, L, P, S, E;
vector<pair<pii, int>> G[MAX];		// 0: original state, 1: changed state, 2: static state
bool trap[MAX];
ll d[MAX][11][2];	// vertex, button's count, state of switched edge

int main() {
	cin >> N >> M >> K >> L >> P;
	
	for(int i = 0; i < K; i++) {
		int x;
		cin >> x;
		
		trap[x] = 1;
	}
	
	for(int i = 0; i < M - L; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		
		G[u].push_back({{v, c}, 2});
	}
	
	for(int i = 0; i < L; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		
		G[u].push_back({{v, c}, 0});
		G[v].push_back({{u, c}, 1});
	}
	
	cin >> S >> E;
	
	// dijkstra starts
	memset(d, 0x3f, sizeof(d));
	priority_queue<pair<pli, pii>> pq;
	pq.push({{0,S},{0,0}});
	d[S][0][0] = 0;
	
	while(!pq.empty()) {
		ll c = -pq.top().fi.fi;
		int u = pq.top().fi.sc;
		int t = pq.top().sc.fi;
		int s = pq.top().sc.sc;
		pq.pop();
		
		if(d[u][t][s] < c) continue;
		
		// check if is a trap
		if(trap[u]) {
			t++;
			if(t == P) t = 0, s = 1 - s; 
		}
		
		for(auto& nxt : G[u]) {
			int v = nxt.fi.fi;
			ll nc = c + nxt.fi.sc;
			int edge_state = nxt.sc;
			
			if(edge_state == 2) {
				if(d[v][t][s] > nc) {
					d[v][t][s] = nc;
					pq.push({{-nc, v},{t, s}});
				}
			} else if(edge_state == s) {
				if(d[v][t][s] > nc) {
					d[v][t][s] = nc;
					pq.push({{-nc, v},{t, s}});
				}
			}
		}
	}
	
	ll ans = INF;
	for(int i = 0; i <= 1; i++) {
		for(int p = 0; p <= P; p++) ans = min(ans, d[E][p][i]);
	}
	cout << (ans == INF ? -1 : ans) << '\n';
	
	return 0;
}
