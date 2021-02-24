#include <iostream>
#include <set>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define sz(x) (int)x.size()

using namespace std;

const int MAX_N = 1e5 + 1;

int p[MAX_N];

int Find(int x) {
	if(p[x] == x) return x;
	return p[x] = Find(p[x]);
}

void Union(int x, int y) {
	x = Find(p[x]); y = Find(p[y]);
	if(x != y) p[x] = y;
}

int main() {
	fastio
	
	int N, M; cin >> N >> M;
	for(int i = 1; i <= N; i++) p[i] = i;

	int cycle = 0;
	for(int i = 0; i < M; i++) {
		int x, y; cin >> x >> y;
		
		if(Find(p[x]) != Find(p[y])) Union(x, y);
		else cycle++;
	}

	set<int> k;
	for(int i = 1; i <= N; i++) k.insert(Find(p[i]));
	cout << sz(k) + cycle - 1 << '\n';
	
	return 0;
}
