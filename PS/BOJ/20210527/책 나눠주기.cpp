#include <iostream>
#include <vector>

using namespace std;

struct MaximumFlow {
	int N;
	vector<vector<int>> G;
	vector<bool> check;
	vector<int> pred;
	
	MaximumFlow(int N) : N(N) {
		G.resize(N);
		check.resize(N);
		pred.resize(N, -1);
	}
	
	void add_edge(int u, int v) {
		G[u].push_back(v);
	}
	
	bool dfs(int x) {
		if(x == -1) return true;
		for(auto& y : G[x]) {
			if(check[y]) continue;
			check[y] = 1;
			if(dfs(pred[y])) {
				pred[y] = x;
				return true;
			}
		}
		return false;
	}
	
	int flow() {
		int ans = 0;
		for(int i = 0; i < N; i++) {
			fill(check.begin(), check.end(), false);
			if(dfs(i)) ans += 1;
		}
		return ans;
	}
};

void solve() {
	int N, M; cin >> N >> M;
	MaximumFlow mf(max(N, M));
	for(int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		for(int j = a - 1; j <= b - 1; j++) mf.add_edge(i, j);
	}
	cout << mf.flow() << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
