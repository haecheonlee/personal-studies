#include <iostream>
#include <vector>

using namespace std;

const int MAX = 20;

vector<int> G[MAX];
int grp[MAX];

void dfs(int x, int g) {
	grp[x] = g;
	for(auto& y : G[x]) if(grp[y] == 0) dfs(y, 3 - g);
}

int main() {
	int N, M;
	cin >> N >> M;
	
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	for(int i = 1; i <= N; i++) if(grp[i] == 0) dfs(i, 1);
	
	bool ans = 1;
	for(int x = 1; x <= N; x++) {
		for(auto& y : G[x]) if(grp[x] == grp[y]) ans = 0;
	}
	cout << (ans ? "POSSIBLE" : "IMPOSSIBLE") << '\n';

	return 0;
}
