/* reference: Yungoon */

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
	int N, K;
	cin >> N >> K;
	
	int cnt = 0;
	for (int i = 1; i < 2 * K - N; i++, cnt++) cout << i << ' ';
	for (int i = K; cnt++ < K; i--) cout << i << ' ';
	cout << '\n';
}

int main() {
	fastio

	int T;
	cin >> T;
	
	while(T--) solve();

	return 0;
}
