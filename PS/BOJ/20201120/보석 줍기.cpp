#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e2 + 1;
const int STATE_MAX = (1 << 14);

int N, M, K;
vector<pii> a[MAX];
int p[MAX];
bool d[MAX][(1 << 14)];

int count_bit(int s) {
	int bit = 0;
	
	for(int i = 0; i < K; i++) {
		if(s & (1 << i)) bit++;
	}
	
	return bit;
}

int main() {
	cin >> N >> M >> K;
	
	memset(p, -1, sizeof(p));
	for(int i = 0; i < K; i++) {
		int x;
		cin >> x;
		
		p[x - 1] = i;
	}
	
	for(int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		
		u--, v--;
		
		a[u].push_back({v, c});
		a[v].push_back({u, c});
	}
	
	// search
	queue<pii> q;
	for(auto& next : a[0]) {
		int y = next.fi;
		
		d[y][0] = 1;
		q.push({y,0});
	}
	
	while(!q.empty()) {
		int x = q.front().fi;
		int s = q.front().sc;
		int c = count_bit(s);
		q.pop();
		
		int ns = -1, nc = -1;
		if(p[x] != -1) {
			ns = (s | (1 << p[x]));
			nc = c + 1;
		}
		
		for(auto& next : a[x]) {
			int y = next.fi;
			int limit = next.sc;
			
			if(ns != -1) {
				// taking treasure
				if(limit >= nc && !d[y][ns]) {
					d[y][ns] = 1;
					q.push({y,ns});
				}
			}
			
			if(limit >= c && !d[y][s]) {
				d[y][s] = 1;
				q.push({y,s});
			}
		}
	}

	int ans = -1;
	for(int s = 1; s < (1 << K); s++) {
		if(d[0][s]) {
			int c = count_bit(s) + (p[0] != -1 && !(s & (1 << 0)));
			ans = max(ans, c);
		}
	}
	cout << (ans == -1 ? 0 : ans);
	
	return 0;
}
