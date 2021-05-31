#include <iostream>
#include <vector>

#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

const int MAX_N = 1e5 + 10;

vector<pii> G[MAX_N];
vector<int> p;
bool check[MAX_N];

int main() {
	int N, M, K; cin >> N >> M >> K;
	for(int i = 1; i <= M; i++) {
		int u, v, c; cin >> u >> v >> c;
		
		G[u].push_back({v, c});
		G[v].push_back({u, c});
	}
	
	p.resize(K);
	for(int i = 0; i < K; i++) {
		cin >> p[i];
		check[p[i]] = 1;
	}
	
	int ans = -1;
	for(auto& x : p) {
		for(auto& nxt : G[x]) {
			if(check[nxt.fi]) continue;
			if(ans == -1 || ans > nxt.sc) ans = nxt.sc;
		}
	}
	cout << ans << '\n';
	
	return 0;
}
