#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 5e4 + 100;

int p[MAX_N];
int cnt[MAX_N];
int g[MAX_N];

int Find(int x) {
	if(p[x] == x) return x;
	return p[x] = Find(p[x]);
}

void Union(int x, int y) {
	x = Find(p[x]);
	y = Find(p[y]);
	
	if(x != y) p[y] = x;
}

int main() {
	int N, M; cin >> N >> M;
	
	for(int i = 1; i <= N; i++) p[i] = i;
	for(int i = 1; i <= M; i++) {
		int u, v; cin >> u >> v;
		Union(u, v);
		cnt[u]++, cnt[v]++;
	}
	
	for(int i = 1; i <= N; i++) g[Find(p[i])]++;
	for(int i = 1; i <= N; i++) {
		if(g[Find(p[i])] != cnt[i] + 1) {
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';
	
	return 0;
}
