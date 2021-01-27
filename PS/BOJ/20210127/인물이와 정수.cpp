#include <iostream>
#include <vector>
#include <queue>

#define fi first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

const int MAX_N = 1e5 + 1;

ll arr[MAX_N];
bool check[MAX_N];
vector<pll> G[MAX_N];

int main() {
	int N, M; cin >> N >> M;
	for(int i = 1; i <= N; i++) cin >> arr[i];
	int P; cin >> P;
	for(int i = 0; i < P; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		
		arr[b] += t;
		G[a].push_back({b,t});
	}
	
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	for(int i = 1; i <= N; i++) pq.push({arr[i], i});
	
	ll ans = 0;
	for(int i = 0; i < M; i++) {
		while(check[pq.top().sc]) pq.pop();
		
		ans = max(ans, pq.top().fi);
		int now = pq.top().sc;
		check[now] = true;
		for(auto& nxt : G[now]) {
			if(check[nxt.fi]) continue;
			arr[nxt.fi] -= nxt.sc;
			pq.push({arr[nxt.fi], nxt.fi});
		}
	}
	cout << ans << '\n';
	
	return 0;
}
