#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;

const ll INF = 1e15;
const int MAX = 1e5 + 1;

vector<pli> a[MAX];
pll d[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for(int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;

		a[u].push_back({c,v});
		a[v].push_back({c,u});
	}

	fill(d, d + N + 1, make_pair(INF, INF));
	priority_queue<pli> q;
	q.push({0, 1});
	d[1].second = 0;

	while(!q.empty()) {
		ll c = -q.top().first;
		int x = q.top().second;
		q.pop();

		if(c&1) { if(d[x].first < c) continue; }
		else { if(d[x].second < c) continue; }
		for(auto& next : a[x]) {
			int y = next.second;
			ll nc = next.first + c;

			if(nc&1) {
				if(d[y].first > nc) {
					d[y].first = nc;
					q.push({-nc, y});
				}
			} else {
				if(d[y].second > nc) {
					d[y].second = nc;
					q.push({-nc, y});
				}
			}
		}
	}

	for(int i = 1; i <= N; i++) {
		cout << (d[i].first == INF ? -1 : d[i].first) << ' ';
		cout << (d[i].second == INF ? -1 : d[i].second) << '\n';
	}

	return 0;
}
