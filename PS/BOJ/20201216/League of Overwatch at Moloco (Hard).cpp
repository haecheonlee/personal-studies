/* reference: junie */

#include <iostream>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX = (1e6 + 1) * 2;

int p[MAX];

int Find(int x) {
	return p[x] == x ? x : p[x] = Find(p[x]);
}

void connect(int x, int y) {
	x = Find(p[x]);
	y = Find(p[y]);
	
	if(x != y) p[x] = y;
}

int main() {
	fastio
	
	int N, M;
	cin >> N >> M;
	
	for(int i = 1; i < MAX; i++) p[i] = i;
	
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		
		connect(u + N, v);
		connect(u, v + N);
	}
	
	bool ans = 1;
	for(int i = 1; i <= N; i++) ans &= Find(i) != Find(N + i);
	cout << (ans ? "POSSIBLE" : "IMPOSSIBLE");
	
	return 0;
}
