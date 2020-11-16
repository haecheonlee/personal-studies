#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 5e2 + 1;

vector<int> a[MAX];
bool check[MAX];

bool dfs(int x, int px) {
	check[x] = true;

	bool is_tree = true;
	for(auto& y : a[x]) {
		if(y == px) continue;
		if(check[y] == false) is_tree = is_tree && dfs(y, x);
		else is_tree = false;
	}

	return is_tree;
}

int main() {	
	int N, M;
	int tc = 1;
	while(cin >> N >> M) {
		if(N == 0 && M == 0) break;

		memset(check, false, sizeof(check));
		for(int i = 1; i < MAX; i++) a[i].clear();

		for(int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;

			a[u].push_back(v);
			a[v].push_back(u);
			if(u == v) check[u] = true;
		}

		int ans = 0;
		for(int i = 1; i <= N; i++) {
			bool is_tree;
			if(check[i] == false) {
				is_tree = dfs(i, -1);
				ans += is_tree;
			}
		}

		cout << "Case " << tc++ << ": ";

		if(ans == 0) cout << "No trees.";
		else if(ans == 1) cout << "There is one tree.";
		else cout << "A forest of " << ans << " trees.";
		cout << '\n';
	}
	
	return 0;
}
