#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

typedef long long ll;

const int MAX = 1e5 + 1;

ll N, K;
ll a[MAX], b[MAX];
vector<ll> p;
ll d[MAX];

ll go(int n) {
	if(n > N) return 0;
	
	ll& ret = d[n];
	if(ret != -1) return ret;
	ret = 0;
	
	// skip
	ret = max(ret, go(n + 1));
	
	// eat
	ll cost = p[b[n]] - p[n - 1];
	if(cost > K) ret = max(ret, go(b[n] + 1) + (cost - K));
	
	return ret;
}

int main() {
	fastio
	
	cin >> N >> K;

	p.resize(N + 1, 0);
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		b[i] = i;	
	}
	
	for(int i = 1; i <= N; i++) p[i] = p[i - 1] + a[i];
	
	for(int i = 1; i <= N; i++) {
		ll k = K + p[i - 1];
		
		int x = lower_bound(p.begin(), p.end(), k) - p.begin();
		if(x <= N) b[i] = x;
	}
	
	memset(d, -1, sizeof(d));
	cout << go(0) << '\n';
	
	return 0;
}
