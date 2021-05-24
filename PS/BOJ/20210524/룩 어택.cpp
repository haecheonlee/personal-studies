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

const int MAX = 3e2 + 10;

bool isEmpty[MAX][MAX];

int main() {
	int N, M, K; cin >> N >> M >> K;
	for(int i = 1; i <= K; i++) {
		int r, c; cin >> r >> c;
		isEmpty[r - 1][c - 1] = 1;
	}
	
	MaximumFlow mf(max(N, M));
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(isEmpty[i][j]) continue;
			mf.add_edge(i, j);
		}
	}
	cout << mf.flow() << '\n';

	return 0;
}
