#include <iostream>
#include <vector>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAX = 1e5 + 1;

vector<pair<int,pii>> G;
int p[MAX];

int Find(int x) {
	return p[x] = (p[x] == x ? x : Find(p[x]));
}

void Union(int x, int y) {
	x = Find(p[x]);
	y = Find(p[y]);
	
	if(x != y) p[x] = y;
}

void solve() {
	// reset
	G.clear();
	
	int N, M, P, Q;
	cin >> N >> M >> P >> Q;
		
	for(int i = 1; i <= N; i++) p[i] = i;
	for(int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		
		G.push_back({c, {u, v}});
	}
		
	sort(G.begin(), G.end());
	
	for(int i = 0; i < M; i++) {
		int u = G[i].sc.fi;
		int v = G[i].sc.sc;
		int cost = G[i].fi;
		
		if(Find(u) != Find(v)) {
			Union(u, v);
			if((u == P && v == Q) || (v == P && u == Q)) {
				cout << "YES\n";
				return;
			}
		}
	}
	
	cout << "NO\n";
}

int main() {
	fastio
	
	int T;
	cin >> T;
	
	while(T--) solve();
	
	return 0;
}
