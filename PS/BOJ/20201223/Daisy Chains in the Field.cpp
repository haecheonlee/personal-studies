#include <iostream>
#include <vector>

using namespace std;

const int MAX = 251;

vector<int> G[MAX];
bool check[MAX];

void dfs(int u) {
	check[u] = true;
	for(auto& v : G[u]) if(!check[v]) dfs(v);
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
	
	dfs(1);
	
	vector<int> ans;
	for(int i = 2; i <= N; i++) if(!check[i]) ans.push_back(i);
	
	if(ans.empty()) cout << 0 << '\n';
	else for(auto& x : ans) cout << x << '\n';
	
	return 0;
}
