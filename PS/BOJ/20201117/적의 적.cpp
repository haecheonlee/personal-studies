#include <iostream>
#include <vector>

using namespace std;

const int MAX = 2e3 + 1;

vector<int> a[MAX];
int g[MAX];

void dfs(int x, int comp) {
	g[x] = comp;
	for(auto& y : a[x]) {
		if(g[y] == 0) dfs(y, 3 - comp);	
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	for(int i = 1; i <= N; i++) {
		if(g[i] == 0) dfs(i,1);
	}
	
	bool ans = true;
	for(int x = 1; x <= N; x++) {
		for(auto& y : a[x]) {
			if(g[x] == g[y]) {
				ans = false;
				break;
			}
		}
	}
	cout << ans;

	return 0;
}
