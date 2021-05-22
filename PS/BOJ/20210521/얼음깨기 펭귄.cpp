#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 3e5 + 5e4 + 10;

vector<int> G[MAX_N];
int h[MAX_N];

void dfs(int x) {
	for(auto& y : G[x]) {
		if(h[y] == -1) {
			h[y] = h[x] + 1;
			dfs(y);
		}
	}
}

int main() {
	int N, S, P; cin >> N >> S >> P;
	for(int i = 0; i < N; i++) {
		int u, v; cin >> u >> v;
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	memset(h, -1, sizeof(h));
	h[P] = 0;
	dfs(P);

	vector<int> a;
	for(int i = 1; i <= S; i++) a.push_back(h[i]);
	sort(a.begin(), a.end());
	
	int ans = N - (a[0] + a[1]);
	if(P > S) ans--;	// if not special block
	cout << ans << '\n';
	
	return 0;
}
