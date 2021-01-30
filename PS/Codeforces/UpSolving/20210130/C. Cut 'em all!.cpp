#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 1;

vector<int> G[MAX_N];
int cnt[MAX_N];
int ans;

void dfs(int x, int p) {
	cnt[x] = 1;
	for(auto& y : G[x]) {
		if(p == y) continue;
		dfs(y, x);
		
		if(cnt[y] % 2 == 0) {
			ans++;
			cnt[y] = 0;
		}
		
		cnt[x] += cnt[y];
	}
}

int main() {
	int N; cin >> N;
	for(int i = 0; i < N - 1; i++) {
		int u, v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1, 0);
	cout << (N & 1 ? -1 : ans) << '\n';
	return 0;
}
