/* reference: MarbinSpectrum */

#include <iostream>
#include <vector>
#include <cstring>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 10;

int a[MAX_N][2];
vector<int> G[MAX_N];
ll d[MAX_N][2];

ll go(int prev, int x, int k) {
	if(d[x][k] != -1) return d[x][k];
	d[x][k] = 0;
	
	for(auto& y : G[x]) {
		if(y == prev) continue;
		
		ll l = go(x, y, 0) + abs(a[x][k] - a[y][0]);
		ll r = go(x, y, 1) + abs(a[x][k] - a[y][1]);
		d[x][k] += max(l, r);
	}
	return d[x][k];
}

void solve() {
	int N; cin >> N;

	// reset
	memset(d, -1, sizeof(d));
	for(int i = 1; i <= N; i++) G[i].clear();
	
	for(int i = 1; i <= N; i++) cin >> a[i][0] >> a[i][1];
	for(int i = 1; i <= N - 1; i++) {
		int u, v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	int leaf = -1;
	for(int i = 1; i <= N; i++) {
		if(G[i].size() == 1) {
			leaf = i;
			break;
		}
	}
	
	ll r1 = go(-1, leaf, 0);
	ll r2 = go(-1, leaf, 1);
	cout << max(r1, r2) << '\n';
}

int main() {
	fastio
	
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
