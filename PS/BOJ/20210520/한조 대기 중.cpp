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
			if(dfs(i)) ans++;
		}
		return ans;
	}
};

int main() {
	int N, M, K1, K2; cin >> N >> M >> K1 >> K2;
	
	MaximumFlow team(max(N, M));
	for(int i = 0; i < K1; i++) {
		int a, b; cin >> a >> b;
		team.add_edge(a - 1, b - 1);
	}
	
	MaximumFlow opponent(max(N, M));
	for(int i = 0; i < K2; i++) {
		int a, b; cin >> a >> b;
		opponent.add_edge(a - 1, b - 1);
	}
	
	int r1 = team.flow();
	int r2 = opponent.flow();

	cout << (r1 < r2 ? "네 다음 힐딱이" : "그만 알아보자") << '\n';

	return 0;
}
