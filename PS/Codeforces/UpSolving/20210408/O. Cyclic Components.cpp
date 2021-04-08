#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 10;

vector<int> G[MAX_N];
bool check[MAX_N];

bool go(int now, int prev, int start) {
	check[now] = 1;
	
	if(now == start) return true;
	if(G[now].size() != 2) return false;
	
	for(auto& nxt : G[now]) {
		if(nxt != prev) {
			if(!check[nxt]) return go(nxt, now, start);
		}
	}
	
	return false;
}

int main() {
	int N, M; cin >> N >> M;
	for(int i = 0; i < M; i++) {
		int u, v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	int ans = 0;
	for(int i = 1; i <= N; i++) {
		if(!check[i]) {
			if(G[i].size() == 2) ans += go(G[i][0], i, i);
		}
	}
	cout << ans << '\n';
	
	return 0;
}
