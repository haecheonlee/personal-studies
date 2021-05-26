/* reference: codeplus/beakoon */

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
			for(int k = 0; k < 2; k++) {
				fill(check.begin(), check.end(), false);
				if(dfs(i)) ans++;
			}
		}
		return ans;
	}
};


const int MAX_N = 60;

int a[MAX_N], b[MAX_N], c[MAX_N];

int main() {
	int N; cin >> N;
	for(int i = 0; i < N; i++) cin >> a[i] >> b[i] >> c[i];
	
	MaximumFlow mf(N);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(i == j) continue;
			
			if(a[i] == a[j] && b[i] == b[j] && c[i] == c[j]) {
				if(i < j) mf.add_edge(i, j);	
			} else if(a[i] >= a[j] && b[i] >= b[j] && c[i] >= c[j]) {
				mf.add_edge(i, j);	
			}
		}
	}
	cout << N - mf.flow() << '\n';

	return 0;
}
