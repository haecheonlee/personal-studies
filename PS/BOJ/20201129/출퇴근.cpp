#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,int> pli;

const int MAX = 2e3 + 1;
const ll INF = 1e15;

int N, M, A, B, K;
vector<pii> G[MAX];
int p[MAX][101];
ll d[MAX][101];

ll dijkstra() {
	memset(d, 0x3f, sizeof(d));
	
	priority_queue<pair<ll,pii>> pq;
	pq.push({0, {0, A}});
	d[A][0] = 0;
	
	while(!pq.empty()) {
		int u = pq.top().second.second;
		int k = pq.top().second.first;
		ll c = -pq.top().first;
		pq.pop();
		
		if(d[u][k] < c) continue;
		
		// use magic
		if(d[u][k + 1] > c && k + 1 <= K) {
			d[u][k + 1] = c;
			pq.push({-c, {k + 1, u}});
		}
		
		for(auto& nxt : G[u]) {
			int v = nxt.first;
			int m = nxt.second;
			
			ll nc = c + p[m][k];
			// don't use magic
			if(d[v][k] > nc) {
				d[v][k] = nc;
				pq.push({-nc, {k, v}});
			}
		}
	}
	
	ll ans = INF;
	for(int k = 0; k <= K; k++) ans = min(ans, d[B][k]);
	
	return ans;
}

int main() {
	cin >> N >> M >> A >> B;
	
	for(int i = 1; i <= M; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		
		G[u].push_back({v, i});
		G[v].push_back({u, i});
		
		p[i][0] = c;
	}
	
	cin >> K;
	
	for(int k = 1; k <= K; k++) {
		for(int m = 1; m <= M; m++) cin >> p[m][k];
	}
	
	cout << dijkstra();

	return 0;
}

int main() {
	cin >> N >> M >> A >> B;
	
	for(int i = 1; i <= M; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		
		G[u].push_back({v, i});
		G[v].push_back({u, i});
		
		p[i][0] = c;
	}
	
	cin >> K;
	
	for(int k = 1; k <= K; k++) {
		for(int m = 1; m <= M; m++) cin >> p[m][k];
	}
	
	cout << dijkstra();

	return 0;
}
