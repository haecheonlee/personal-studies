#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>

#define sz(x) (int)(x.size())
#define fi first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX_N = 2e5 + 1;

int N;
ll a[MAX_N];
ll d[MAX_N];
bool check[MAX_N];

ll dfs(int x, ll sum) {
	int nxt = x + a[x];
	if(nxt <= N && d[nxt] < sum + a[x]) {
		d[nxt] = sum + a[x];
		return dfs(x + a[x], sum + a[x]);
	} else {
		return sum + a[x];
	}
}

void solve() {
	cin >> N;
	
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		check[i] = false;
		d[i] = 0;
	}
	
	ll ans = 0;
	for(int i = 1; i <= N; i++) ans = max(ans, dfs(i, 0));
	cout << ans << '\n';
}

int main() {
	int T;
	cin >> T;

	while(T--) solve();

	return 0;
}
