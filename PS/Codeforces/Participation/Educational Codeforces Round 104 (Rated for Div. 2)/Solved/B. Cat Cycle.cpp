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
	int N, K; cin >> N >> K;
	K--;
	if(K == 0) {
		cout << 1 << '\n';
	} else {
		if(N & 1) {
			ll two = (K / (N / 2));
			ll one = K - two;
			ll total = one + two * 2;
			cout << 1 + (total % N) << '\n';;
		} else {
			cout << 1 + (K % N) << '\n';
		}
	}
}

int main() {
	fastio

	int T; cin >> T;
	while(T--) solve();

	return 0;
}
