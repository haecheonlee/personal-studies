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

int main() {
	int N, M; cin >> N >> M;
	
	int a[N];
	for(int i = 0; i < N; i++) cin >> a[i];
	
	int b[M];
	for(int i = 0; i < M; i++) cin >> b[i];
	
	MaximumFlow mf(max(N, M));
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			int l1 = (a[i] + 1) / 2, r1 = (a[i] * 3) / 4;
			int l2 = a[i], r2 = (a[i] * 5) / 4;
			
			if((l1 <= b[j] && b[j] <= r1) || (l2 <= b[j] && b[j] <= r2)) {
				mf.add_edge(i, j);
			}
		}
	}
	cout << mf.flow() << '\n';
	
	return 0;
}
