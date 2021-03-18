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

void solve() {
	int N, K1, K2; cin >> N >> K1 >> K2;
	int w, b; cin >> w >> b;
	
	int W = (K1 + K2);
	int B = (N * 2) - W;
	
	W /= 2, B /= 2;
	cout << (W >= w && B >= b ? "YES" : "NO") << '\n';
}

int main() {
	fastio

	int T; cin >> T;
	while(T--) solve();

	return 0;
}
