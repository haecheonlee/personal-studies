#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

const int MAX = 12;

int N, M, K;
vector<pii> a[MAX];
vector<pair<int,pii>> p;	// {type, {last index is house's cooridnate}}
bool d[MAX][MAX * MAX][(1 << 10)];

void dfs(int x, int m, int s) {
	d[x][m][s] = 1;

	if(p[x].fi == 2) {
		if(!(s & (1 << x))) {
			m += K;
			s |= (1 << x);
		}
	}
	
	for(auto& next : a[x]) {
		int y = next.fi;
		int need = next.sc;
		
		// skip visited one
		if(s & (1 << y)) continue;
		if(m >= need) {
			if(!d[y][m - need][s]) dfs(y, m - need, s);
		}
	}
}

int count_bit(int k) {
	int bit = 0;
	
	while(k) {
		if(k&1) bit++;
		k >>= 1;
	}
	
	return bit;
}

int main() {
	cin >> N >> M >> K;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			int x;
			cin >> x;
			
			if(x != 0) p.push_back({x, {i,j}});
		}
	}

	sort(p.rbegin(), p.rend());
	
	for(int i = 0; i < (int)p.size(); i++) {
		for(int j = i + 1; j < (int)p.size(); j++) {
			int c = abs(p[i].sc.fi - p[j].sc.fi) + abs(p[i].sc.sc - p[j].sc.sc);
			
			a[i].push_back({j, c});
			a[j].push_back({i, c});
		}
	}
	
	int S = (int)p.size() - 1;
	dfs(S, M, 0);
	
	int ans = 0;
	for(int i = 0; i <= 100; i++) {
		for(int k = 0; k < (1 << 10); k++) {
			if(d[S][i][k]) ans = max(ans, count_bit(k));
		}
	}
	cout << ans;
	
	return 0;
}
