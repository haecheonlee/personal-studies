#include <iostream>
#include <vector>
#include <unordered_map>
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
	int N, M; cin >> N >> M;
	
	int idx = 0;
	unordered_map<string,int> ump;
	for(int i = 0; i < M; i++) {
		string s; cin >> s;
		ump[s] = idx++;
	}
	
	MaximumFlow mf(max(N, idx));
	for(int i = 0; i < N; i++) {
		int K; cin >> K;
		while(K--) {
			string s; cin >> s;
			mf.add_edge(i, ump[s]);
		}
	}
	
	int ans = mf.flow();
	if(ans == N) cout << "YES" << '\n';
	else cout << "NO" << '\n' << ans << '\n';
	
	return 0;
}
