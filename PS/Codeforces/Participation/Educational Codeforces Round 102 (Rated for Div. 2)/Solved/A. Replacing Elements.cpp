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
	int N, D;
	cin >> N >> D;

	int a[N + 1];
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	bool is_good = false, is_all_less = true;
	for(int i = 1; i <= N; i++) if(a[i] > D) is_all_less = false;
	is_good = is_all_less;

	for(int i = 1; i <= N && !is_good; i++) {
		for(int j = 1; j <= N; j++) {
			if(i == j) continue;
			if(a[i] + a[j] <= D) is_good = true;
		}
	}
	
	cout << (is_good ? "YES" : "NO") << '\n';
}

int main() {
	fastio

	int T;
	cin >> T;

	while(T--) solve();

	return 0;
}
