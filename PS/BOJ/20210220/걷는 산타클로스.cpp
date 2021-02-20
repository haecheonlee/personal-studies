#include <iostream>
#include <vector>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int MAX = 1e5 + 10;

pll a[MAX];
ll x[MAX], y[MAX];

int main() {
	fastio
	
	int N, M, K; cin >> N >> M >> K;
	for(int i = 0; i < K; i++) {
		cin >> a[i].fi >> a[i].sc;
		x[i] = a[i].fi, y[i] = a[i].sc;
	}
	sort(x, x + K); sort(y, y + K);
	
	vector<int> xP, yP;
	xP.push_back(x[(K - 1) / 2]); xP.push_back(x[K / 2]);
	yP.push_back(y[(K - 1) / 2]); yP.push_back(y[K / 2]);

	pair<ll, pii> ans { 1e18, {-1, -1} };
	for(auto& xx : xP) {
		for(auto& yy : yP) {
			ll sum = 0, cnt = 0;
			for(int i = 0; i < K; i++) {
				ll dist = abs(xx - a[i].fi) + abs(yy - a[i].sc);
				cnt = max(cnt, dist);
				
				sum += dist * 2;
			}
			sum -= cnt;
			
			if(ans.fi > sum) ans.fi = sum, ans.sc.fi = xx, ans.sc.sc = yy;
		}
	}

	cout << ans.fi << '\n';
	cout << ans.sc.fi << ' ' << ans.sc.sc << '\n';
	
	return 0;
}
