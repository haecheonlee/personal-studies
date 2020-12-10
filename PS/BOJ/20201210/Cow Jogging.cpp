#include <iostream>
#include <vector>
#include <queue>

#define fi first
#define sc second
#define sz(x) (int)(x.size())

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e3 + 1;

vector<pii> G[MAX];
priority_queue<int> d[MAX];

int main() {
	int N, M, K;
	cin >> N >> M >> K;

	for(int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		
		G[u].push_back({v,c});
	}
	
	priority_queue<pii> pq;
	pq.push({0,N});
	d[N].push(0);

	while(!pq.empty()) {
		int c = -pq.top().fi;
		int u = pq.top().sc;
		pq.pop();
		
		for(auto& nxt : G[u]) {
			int v = nxt.fi;
			int nc = c + nxt.sc;
			
			if(sz(d[v]) < K || d[v].top() > nc) {
				if(sz(d[v]) == K) d[v].pop();

				d[v].push(nc);
				pq.push({-nc, v});
			}
		}
	}
	
	vector<int> ans;
	while(!d[1].empty()) {
		ans.push_back(d[1].top());
		d[1].pop();
	}
	
	for(int i = sz(ans) - 1; i >= 0; i--) cout << ans[i] << '\n';
	for(int i = sz(ans) + 1; i <= K; i++) cout << -1 << '\n';

	return 0;
}
