/* reference: codeplus/beakjoon */

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

const int MAX = 60;

char board[MAX][MAX];
int col[MAX][MAX], row[MAX][MAX];

int main() {
	int N, M; cin >> N >> M;
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) {
		cin >> board[i][j];
	}
	
	int colNum = 0, rowNum = 0;
	
	// col
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) {
		if(board[i][j] == '*') {
			if(j - 1 < 0 || board[i][j - 1] == '.') col[i][j] = ++colNum;
			else if(board[i][j - 1] == '*') col[i][j] = col[i][j - 1];
		}
	}

	// row
	for(int j = 0; j < M; j++) for(int i = 0; i < N; i++) {
		if(board[i][j] == '*') {
			if(i - 1 < 0 || board[i - 1][j] == '.') row[i][j] = ++rowNum;
			else if(board[i - 1][j] == '*') row[i][j] = row[i - 1][j];
		}
	}
	
	MaximumFlow mf(max(colNum, rowNum));
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) {
		if(col[i][j] > 0 && row[i][j] > 0) mf.add_edge(col[i][j] - 1, row[i][j] - 1);
	}
	cout << mf.flow() << '\n';

	return 0;
}
