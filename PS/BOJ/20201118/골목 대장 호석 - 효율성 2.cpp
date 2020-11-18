#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,int> pii;

const int MAX = 1e5 + 1;
const ll INF = 1e15;

int N, M, A, B;
ll C;
vector<pii> G[MAX];
ll d[MAX];

bool dijkstra(int K) {
	memset(d, 0x3f, sizeof(d));
	
	priority_queue<pli> q;
	q.push({0,A});
	d[A] = 0;
	
	while(!q.empty()) {
		int x = q.top().second;
		ll c = -q.top().first;
		q.pop();
		
		if(d[x] < c) continue;
		for(auto& next : G[x]) {
			int y = next.first;
			ll cc = next.second;

			ll nc = c + cc;
			if(nc > C || cc > K) continue;
			if(d[y] > nc) {
				d[y] = nc;
				q.push({-nc, y});
			}
		}
	}
	
	return d[B] <= C;
}

int main() {
	cin >> N >> M >> A >> B >> C;
	
	for(int i = 0; i < M; i++) {
		int U, V, C;
		cin >> U >> V >> C;
		
		G[U].push_back({V,C});
		G[V].push_back({U,C});
	}
	
	int ans = -1;
	int L = 1, R = 1e9;
	while(L <= R) {
		int mid = (L + R) / 2;
		
		if(dijkstra(mid)) {
			ans = mid;
			R = mid - 1;
		} else {
			L = mid + 1;
		}
	}
	cout << ans;
	
	return 0;
}
