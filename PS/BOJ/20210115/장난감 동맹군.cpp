#include <iostream>
#include <vector>
#include <cstring>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX_N = 1e5 + 1;

vector<vector<int>> a;
vector<int> g;

void dfs(int x, int grp) {
	g[x] = grp;
	for(auto& y : a[x]) {
		if(g[y] == 0) dfs(y, 3 - grp);
	}
}

int main() {
	fastio
	
	int T;
	cin >> T;
	
	while(T--) {
		int N, M;
		cin >> N >> M;
		
		// reset
		g.resize(N + 1);
		a.resize(N + 1);
		for(int i = 1; i <= N; i++) a[i].clear(), g[i] = 0;
		
		for(int i = 0; i < M; i++) {
			int x, y;
			cin >> x >> y;
			
			a[x].push_back(y);
			a[y].push_back(x);
		}

		for(int x = 1; x <= N; x++) if(g[x] == 0) dfs(x, 1);

		bool is_good = 1;
		for(int x = 1; x <= N; x++) {
			for(auto& y : a[x]) if(g[x] == g[y]) is_good = 0;
		}
		
		cout << (is_good ? "YES" : "NO") << '\n';
	}

	return 0;
}
