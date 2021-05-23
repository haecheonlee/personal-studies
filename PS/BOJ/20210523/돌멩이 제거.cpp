/* reference: codeplus/baekjoon */

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
	
	void add_edge(int u, int v){
		G[u].push_back(v);
	}
	
	bool dfs(int x) {
		if(x == -1) return true;
		for(auto& y : G[x]) {
			if(check[y]) continue;
			check[y] = true;
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
			if(dfs(i)) ans++;
		}
		return ans;
	}
};

int main() {
	int N, K; cin >> N >> K;
	MaximumFlow mf(N);
	for(int i = 0; i < K; i++) {
		int u, v; cin >> u >> v;
		mf.add_edge(u - 1, v - 1);
	}
	cout << mf.flow() << '\n';

	return 0;
}
