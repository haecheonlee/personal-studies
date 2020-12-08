#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define fi first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

const int MAX = 111;
const long long INF = 1e12;

int p[12], pp[12];
vector<pii> G[MAX];
ll d[12][MAX];

void dijkstra(int sx) {
	priority_queue<pli> pq;
	pq.push({0, p[sx]});	// distance, {city}
	d[sx][p[sx]] = 0;

	while(!pq.empty()) {
		ll c = -pq.top().fi;
		int u = pq.top().sc;
		pq.pop();

		if(d[sx][u] < c) continue;
		for(auto& nxt : G[u]) {
			int v = nxt.fi;
			ll nc = (nxt.sc * pp[sx]) + c;
			
			if(d[sx][v] > nc) {
				d[sx][v] = nc;
				pq.push({-nc, v});
			}
		}
	}
}

int main() {
	int T;
	cin >> T;

	for(int tc = 1; tc <= T; tc++) {
		int N, P, M;
		cin >> N >> P >> M;

		// reset
		for(int i = 1; i <= N; i++) G[i].clear();

		for(int k = 1; k <= P; k++) cin >> p[k] >> pp[k];

		for(int i = 0; i < M; i++) {
			int D, L;
			cin >> D >> L;

			vector<int> city(L);
			for(int k = 0; k < L; k++) cin >> city[k];

			for(int k = 1; k < L; k++) {
				G[city[k]].push_back({city[k - 1], D});
				G[city[k - 1]].push_back({city[k], D});
			}
		}

		memset(d, 0x3f, sizeof(d));
		for(int k = 1; k <= P; k++) dijkstra(k);

		ll ans = INF;
		for(int i = 1; i <= N; i++) {
			ll total = 0;
			for(int k = 1; k <= P; k++) total = max(total, d[k][i]);
			ans = min(ans, total);
		}

		cout << "Case #" << tc << ": " << (ans >= INF ? -1 : ans) << '\n';
	}

	return 0;
}
