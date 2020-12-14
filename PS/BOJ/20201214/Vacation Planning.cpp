/* reference: green55 */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define fi first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 2e4 + 1;
const int INF = 987654321;

int N, M, K, Q;
vector<pii> G[MAX], RG[MAX];
int hub[201], query[50001][2], ret[50001];
vector<int> query_start_at[20001];

int d[MAX];
void dijkstra(int S) {
	fill(d, d + MAX, INF);
	
	priority_queue<pii> pq;
	pq.push({0, S});
	d[S] = 0;
	
	while(!pq.empty()) {
		int c = -pq.top().fi;
		int u = pq.top().sc;
		pq.pop();
		
		if(d[u] < c) continue;
		for(auto& nxt : G[u]) {
			int v = nxt.fi;
			int nc = c + nxt.sc;
			
			if(d[v] > nc) {
				d[v] = nc;
				pq.push({-nc, v});
			}
		}
	}
	
	for(auto& p : RG[S]) {
		for(int query_number : query_start_at[p.fi]) {
			ret[query_number] = min(ret[query_number], p.sc + d[query[query_number][1]]);
		}
	}
	
	for(int i = 0; i < Q; i++) {
		if(query[i][0] == S) ret[i] = min(ret[i], d[query[i][1]]);
	}
}

int main() {
	cin >> N >> M >> K >> Q;
	
	for(int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		
		G[u].push_back({v, c});
		RG[v].push_back({u, c});
	}
	
	for(int i = 0; i < K; i++) cin >> hub[i];
	
	for(int i = 0; i < Q; i++) {
		cin >> query[i][0] >> query[i][1];
		query_start_at[query[i][0]].push_back(i);
	}
	
	fill(ret, ret + Q, INF);
	for(int i = 0; i < K; i++) dijkstra(hub[i]);
	
	pll ans = {0, 0};
	for(int i = 0; i < Q; i++) {
		if(ret[i] >= INF) continue;
		ans.fi++;
		ans.sc += ret[i];
	}
	cout << ans.fi << '\n' << ans.sc;
	
	return 0;
}
