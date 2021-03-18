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

const int MAX_N = 1e2 + 10;

string s;
int N;
int d[MAX_N][MAX_N][2];

int go(int now, int prev, int skipped) {
	if(now == N) {
		return 1;
	}
	
	int& ret = d[now][prev][skipped];
	if(ret != -1) return ret;
	ret = 0;

	if(!skipped) {
		// skip
		ret = max(ret, go(now + 1, prev, 1));
	}
	
	if(!(s[now] == '0' && s[prev] == '1')) {
		ret = max(ret, go(now + 1, now, 0));
	}

	return ret;
}

void solve() {
	cin >> s;
	s = 'A' + s;
	N = sz(s);

	memset(d, -1, sizeof(d));
	cout << (go(1, 0, 0) == 1 ? "YES" : "NO") << '\n';
}

int main() {
	fastio

	int T; cin >> T;
	while(T--) solve();

	return 0;
}
