#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

const int MAX = 1e4 + 1;
const ll INF = 1e15;

int N, M;
vector<pii> a[MAX];
ll d[10], dd[MAX], ddd[MAX];
int p[10];
int S;

ll dijkstra(int sx, int ex) {
	fill(dd, dd + N + 1, INF);

	priority_queue<pli> q;
	q.push({0, sx});
	dd[sx] = 0;

	while(!q.empty()) {
		int x = q.top().second;
		ll c = -q.top().first;
		q.pop();

		if(x == ex) return c;
		if(dd[x] < c) continue;
		for(auto& next : a[x]) {
			int y = next.first;
			ll nc = c + next.second;

			if(dd[y] > nc) {
				dd[y] = nc;
				q.push({-nc, y});
			}
		}
	}

	return INF;
}

void dijkstra2(int sx) {
	fill(ddd, ddd + N + 1, INF);
	
	priority_queue<pli> q;
	q.push({0, sx});
	ddd[sx] = 0;

	while(!q.empty()) {
		int x = q.top().second;
		ll c = -q.top().first;
		q.pop();

		if(ddd[x] < c) continue;
		for(auto& next : a[x]) {
			int y = next.first;
			ll nc = c + next.second;

			if(ddd[y] > nc) {
				ddd[y] = nc;
				q.push({-nc, y});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for(int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;

		a[u].push_back({v,c});
		a[v].push_back({u,c});
	}

	for(int i = 0; i < 10; i++) cin >> p[i];
	cin >> S;

	// dijkstra 1
	fill(d, d + 10, INF);
	d[0] = 0;

	for(int i = 0; i < 9; i++) {
		for(int j = i + 1; j < 10; j++) {
			ll dist = dijkstra(p[i], p[j]);
			if(dist >= INF) continue;

			d[j] = d[i] + dist;
			i = j - 1;

			break;
		}
	}

	// dijkstra 2
	dijkstra2(S);

	int ans = -1;
	for(int i = 0; i < 10; i++) {
		if(ddd[p[i]] >= INF || d[i] >= INF) continue;
		if(ddd[p[i]] <= d[i]) {
			if(ans == -1 || ans > p[i]) ans = p[i];
		}
	}
	cout << ans;

	return 0;
}
