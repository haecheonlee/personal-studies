#include <iostream>
#include <vector>
#include <queue>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;
typedef pair<int,int> pii;

const int MAX_N = 1e4 + 2;

int N, M;
ll d[MAX_N];
vector<pii> G[MAX_N];

int main() {
	fastio

	cin >> N >> M;
	for(int i = 1; i <= N; i++) cin >> d[i];
	
	for(int i = 1; i <= M; i++) {
		int a, x, y; cin >> a >> x >> y;
		
		G[x].push_back({a, y});
		G[y].push_back({a, x});
	}

	priority_queue<pli, vector<pli>, greater<pli>> pq;
	for(int i = 1; i <= N; i++) pq.push({d[i], i});
	
	while(!pq.empty()) {
		ll c = pq.top().first;
		int x = pq.top().second;
		pq.pop();
		
		if(d[x] < c) continue;
		for(auto& nxt : G[x]) {
			int y = nxt.first;
			int xx = nxt.second;
			
			ll nc = c + d[xx];
			if(d[y] > nc) {
				d[y] = nc;
				pq.push({d[y], y});
			}
		}
	}
	
	cout << d[1] << '\n';

	return 0;
}
