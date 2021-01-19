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
	int N;
	cin >> N;

	string b;
	cin >> b;

	string ans = "1";
	for(int i = 1; i < N; i++) {
		int prv = (ans[i - 1] - '0') + (b[i - 1] - '0');
		if(b[i] == '0') {
			if(prv == 1) ans += "0";
			else ans += "1";
		} else {
			if(prv == 2) ans += "0";
			else ans += "1";
		}
	}
	cout << ans << '\n';
}

int main() {
	fastio

	int T;
	cin >> T;

	while(T--) solve();

	return 0;
}
