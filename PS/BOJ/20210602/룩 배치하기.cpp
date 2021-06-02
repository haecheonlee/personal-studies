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
			if(dfs(i)) ans++;
		}
		return ans;
	}
};

const int MAX = 1e2 + 10;

char board[MAX][MAX];
int r[MAX][MAX], c[MAX][MAX];

int main() {
	int N; cin >> N;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
		cin >> board[i][j];
	}
	
	int cn = 0;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
		if(board[i][j] == '.') {
			if(j - 1 < 0 || board[i][j - 1] == 'X') c[i][j] = ++cn;
			else if(board[i][j - 1] == '.') c[i][j] = c[i][j - 1];
		}
	}
	
	int rn = 0;
	for(int j = 0; j < N; j++) for(int i = 0; i < N; i++) {
		if(board[i][j] == '.') {
			if(i - 1 < 0 || board[i - 1][j] == 'X') r[i][j] = ++rn;
			else if(board[i - 1][j] == '.') r[i][j] = r[i - 1][j];
		}
	}

	MaximumFlow mf(max(cn, rn));
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
		if(board[i][j] == '.' && r[i][j] > 0 && c[i][j] > 0) {
			mf.add_edge(r[i][j] - 1, c[i][j] - 1);
		}
	}
	cout << mf.flow() << '\n';
	
	return 0;
}
