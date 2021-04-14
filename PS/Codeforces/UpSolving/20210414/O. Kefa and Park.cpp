#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 10;

int N, M;
bool check[MAX_N], visited[MAX_N], leaf[MAX_N];
vector<int> G[MAX_N];

void dfs(int now, int prev, int k) {
	visited[now] = 1;

	bool traveled = false;
	for(auto& nxt : G[now]) {
		if(nxt == prev) continue;
		
		int nk = (check[nxt] ? k + 1 : 0);
		if(nk <= M) dfs(nxt, now, nk);
		traveled = true;
	}
	
	if(!traveled) leaf[now] = 1;
}

int main() {
	cin >> N >> M;
	for(int i = 1; i <= N; i++) {
		int x; cin >> x;
		check[i] = x;
	}
	
	for(int i = 0; i < N - 1; i++) {
		int u, v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1, -1, check[1]);
	
	int ans = 0;
	for(int i = 2; i <= N; i++) ans += (leaf[i] && visited[i]);
	cout << ans << '\n';
	
	return 0;
}
