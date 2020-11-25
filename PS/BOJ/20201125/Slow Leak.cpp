/* reference: queued_q */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 5e2 + 1;
const ll INF = 1e18;

int N, M, T, D;
bool repair[MAX];
ll w[MAX][MAX], d[MAX];

int main() {
	cin >> N >> M >> T >> D;
	
	for(int i = 0; i < T; i++) {
		int x;
		cin >> x;
		
		repair[x] = true;
	}
	repair[1] = repair[N] = true;
	
	for(int i = 1; i <= N; i++) {
		d[i] = INF;
		for(int j = 1; j <= N; j++) 
			w[i][j] = (i == j ? 0 : INF);
	}
	
	for(int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		w[u][v] = w[v][u] = c;
	}
	
	for(int k = 1; k <= N; k++) {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
			}
		}
	}
	
	priority_queue<pll, vector<pll>, greater<pll>> q;
	q.push({0, 1});
	d[1] = 0;
	
	ll ans = -1;
	while(!q.empty()) {
		ll dist = q.top().first;
		int u = q.top().second;
		q.pop();
		
		if(u == N) { ans = dist; break; }
		if(d[u] < dist) continue;
		for(int v = 1; v <= N; v++) {
			if(u == v || !repair[v] || w[u][v] > D) continue;
			if(d[v] > dist + w[u][v]) {
				d[v] = dist + w[u][v];
				q.push({d[v], v});
			}
		}
	}
	
	if(ans == -1) cout << "stuck";
	else cout << ans;
	
	return 0;
}
