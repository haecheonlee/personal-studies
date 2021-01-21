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

const int MAX_N = 1e6 + 1;

int v[MAX_N];

void solve() {
	string s;
	cin >> s;

	memset(v, 0, sizeof(v));
	s = '0' + s;
	
	vector<int> o;
	for(int i = 1; i < sz(s); i++) {
		if(s[i] == 'o') o.push_back(i);
		v[i] = v[i - 1] + (s[i - 1] == 'v' && s[i] == 'v');
	}
	
	ll ans = 0;
	for(auto& x : o) ans += 1LL * (v[x - 1]) * (v[sz(s) - 1] - v[x]);
	cout << ans << '\n';
}

int main() {
	fastio

	solve();

	return 0;
}
