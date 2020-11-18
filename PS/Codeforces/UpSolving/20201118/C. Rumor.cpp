#include <iostream>
#include <vector>

#define eb emplace_back

using namespace std;

typedef long long ll;

const int MAX = 1e5 + 1;

int c[MAX];
vector<int> a[MAX];
bool check[MAX];

int dfs(int x) {
	check[x] = true;
	int mn = c[x];

	for(auto& y : a[x]) {
		if(check[y] == false) mn = min(mn, dfs(y));
	}

	return mn;
}

int main() {
	int N, M;
	cin >> N >> M;

	for(int i = 1; i <= N; i++) cin >> c[i];

	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		a[u].eb(v);
		a[v].eb(u);
	}

	ll ans = 0;
	for(int i = 1; i <= N; i++) {
		if(check[i] == false) ans += dfs(i);
	}
	cout << ans;

	return 0;
}
