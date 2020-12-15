#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e3 + 1;

int p[MAX];
set<int> ans[MAX];

int Find(int x) {
	if(p[x] == x) return x;
	return p[x] = Find(p[x]);
}

void Union(int x, int y) {
	x = Find(p[x]);
	y = Find(p[y]) ;
	
	if(x != y) p[y] = x;
}

int main() {
	fastio
	
	int N, M;
	cin >> N >> M;
	
	int B, C;
	cin >> B >> C;
	
	vector<pair<int,pii>> G;
	for(int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		
		G.push_back({c, {u, v}});
	}
	
	sort(G.rbegin(), G.rend());
	
	for(int i = 0; i < N; i++) p[i] = i;
	
	for(int i = 0; i < M; i++) {
		int u = G[i].sc.fi;
		int v = G[i].sc.sc;
		int cost = G[i].fi;
		
		if(Find(B) == Find(C)) break;
		if(Find(u) != Find(v)) {
			Union(u, v);
			ans[Find(u)].insert(cost);
		}
	}
	
	cout << *ans[Find(B)].begin() << '\n';

	return 0;
}
