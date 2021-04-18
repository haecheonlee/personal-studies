/* reference: coloredrabbit & alsrl9 */

#include <iostream>
#include <queue>
#include <cstring>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

const int MAX_N = 2e3 + 10;
const int INF = 1e9;

int a[MAX_N];
int d[MAX_N];

int main() {
	fastio
	
	int N; cin >> N;
	for(int i = 1; i <= N - 1; i++) cin >> a[i];
	
	fill(d, d + MAX_N, INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, 0});
	d[0] = 0;
	
	while(!pq.empty()) {
		int c = pq.top().fi;
		int x = pq.top().sc;
		pq.pop();
		
		if(d[x] < c) continue;
		for(int y = 0; y < N; y++) {
			if(x == y) continue;
			
			int nc = INF;
			if(x > y && a[x - y]) nc = a[x - y] + c;
			if(x < y && a[x - y + N]) nc = a[x - y + N] + c;
			
			if(d[y] > nc) {
				d[y] = nc;
				pq.push({nc, y});
			}
		}
	}
	
	int Q; cin >> Q;
	while(Q--) {
		int u, v; cin >> u >> v;
		v -= u; if(v < 0) v += N;
		cout << (d[v] == INF ? -1 : d[v]) << '\n';
	}
	
	return 0;
}
