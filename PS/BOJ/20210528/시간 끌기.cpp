#include <iostream>
#include <vector>
#include <cstring>

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

int main() {
	int N, M, K; cin >> N >> M >> K;
	
	MaximumFlow mf(max(N, M));
	for(int i = 0; i < K; i++) {
		int a, b; cin >> a >> b;
		a--, b--;
		mf.add_edge(a, b);
	}
	cout << (N + M) - mf.flow() << '\n';

	return 0;
}
