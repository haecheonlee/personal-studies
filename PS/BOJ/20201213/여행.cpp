/* reference: https://kibbomi.tistory.com/67 */

#include <iostream>
#include <vector>
#include <cstring>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

const int MAX = 3e2 + 1;

int N, K, M;
vector<pii> G[MAX];
int d[MAX][MAX];

int main() {
	fastio
	cin >> N >> K >> M;
	
	for(int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		
		if(u < v) G[u].push_back({v, c});
	}
	
	// start
	for(auto& nxt : G[1]) {
		int v = nxt.fi;
		int cost = nxt.sc;
		
		d[v][2] = max(d[v][2], cost);
	}
	
	for(int k = 2; k <= K; k++) {
		for(int u = 2; u <= N; u++) {
			if(d[u][k] != 0) {
				for(auto& nxt : G[u]) {
					int v = nxt.fi;
					int cost = nxt.sc;
					
					d[v][k + 1] = max(d[v][k + 1], d[u][k] + cost);
				}
			}
		}
	}
	
	int ans = 0;
	for(int k = 2; k <= K; k++) ans = max(ans, d[N][k]);
	cout << ans << '\n';

	return 0;
}
