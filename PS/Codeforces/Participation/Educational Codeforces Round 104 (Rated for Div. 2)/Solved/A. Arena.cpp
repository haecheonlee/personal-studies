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
	int N; cin >> N;
	int a[N];
	for(int i = 0; i < N; i++) cin >> a[i];
	
	int ans = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(i == j) continue;
			if(a[i] > a[j]) {
				ans++;
				break;
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	fastio

	int T; cin >> T;
	while(T--) solve();

	return 0;
}
