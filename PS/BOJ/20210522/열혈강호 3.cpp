#include <iostream>
#include <vector>

using namespace std;

struct MaximumFlow {
	int N, K;
	vector<vector<int>> G;
	vector<bool> check;
	vector<int> pred;
	
	MaximumFlow(int N, int K) : N(N), K(K) {
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
			if(dfs(i)) ans++;
		}
		
		int cnt = 0;
		for(int i = 0; i < N; i++) {
			fill(check.begin(), check.end(), false);
			if(dfs(i)) ans++, cnt++;
			if(cnt == K) break;
		}
		
		return ans;
	}
};

int main() {
	int N, M, K; cin >> N >> M >> K;

	MaximumFlow mf(max(N, M), K);
	for(int i = 0; i < N; i++) {
		int Q; cin >> Q;
		while(Q--) {
			int x; cin >> x;
			mf.add_edge(i, x - 1);
		}
	}
	cout << mf.flow() << '\n';

	return 0;
}
