/* reference: codeplus/beakjoon */

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
		for(int& nxt : G[x]) {
			if(check[nxt]) continue;
			check[nxt] = true;
			
			if(dfs(pred[nxt])) {
				pred[nxt] = x;
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
	int N, M; cin >> N >> M;
	MaximumFlow mf(max(N, M));
	
	for(int i = 0; i < N; i++) {
		int K; cin >> K;
		while(K--) {
			int task; cin >> task;
			mf.add_edge(i, task - 1);
		}
	}
	cout << mf.flow() << '\n';
	
	return 0;
}
