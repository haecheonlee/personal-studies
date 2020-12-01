#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e3 + 1;
const int INF = 1e9;

int N, M;
vector<pair<int,pii>> G[MAX];
int d[MAX][MAX * 2];

int go(int u, int k, int b) {
	if(k > 1000 || b > 1000) return INF;
	if(u == N - 1) return k * b;

	int& ret = d[u][k + b];
	if(ret != -1) return ret;
	ret = INF;
	
	for(auto& nxt : G[u]) {
		int v = nxt.fi;
		int kk = nxt.sc.fi;
		int bb = nxt.sc.sc;
		
		ret = min(ret, go(v, k + kk, b + bb));
	}
	
	return ret;
}

int main() {
	cin >> N >> M;
	
	for(int i = 0; i < M; i++) {
		int u, v, c, t;
		cin >> u >> v >> c >> t;
		
		G[u].push_back({v, {c, t}});
		G[v].push_back({u, {c, t}});
	}
	
	memset(d, -1, sizeof(d));
	int ans = go(0, 0, 0);
	cout << (ans == INF ? -1 : ans);
	
	return 0;
}
