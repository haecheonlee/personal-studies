#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define sz(x) (int)(x.size())
#define fi first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX_N = 2e5 + 1;

ll a[MAX_N];

void solve() {
	int N;
	cin >> N;

	for(int i = 1; i <= N; i++) cin >> a[i];

	bool ans = 1;
	
	ll sum = 0;
	for(int i = 1; i <= N && ans; i++) {
		sum += a[i];
		if(sum <= 0) ans = 0;
	}

	sum = 0;
	for(int i = N; i >= 1 && ans; i--) {
		sum += a[i];
		if(sum <= 0) ans = 0;
	}

	cout << (ans ? "YES" : "NO") << '\n';
}

int main() {
	fastio

	int T;
	cin >> T;

	while(T--) solve();

	return 0;
}
