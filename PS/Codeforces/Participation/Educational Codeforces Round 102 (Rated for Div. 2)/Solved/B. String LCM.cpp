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

int gcd(int a, int b) {
	return (b == 0 ? a : gcd(b, a % b));
}

string findPattern(string& s) {
	for(int i = 1; i <= sz(s); i++) {
		string x = s.substr(0, i);
		bool chk = true;
		for(int j = 0; j < sz(s) && chk; j += i) {
			if(x != s.substr(j, i)) chk = false;
		}

		if(chk) return x;
	}

	return s;
}

void solve() {
	string s, t;
	cin >> s >> t;

	if(sz(s) < sz(t)) swap(s, t);
	string sP = findPattern(s), tP = findPattern(t);

	if(sP != tP) {
		cout << -1 << '\n';
	} else if(s == t) {
		cout << s << '\n';
	} else {
		int p = sz(sP);
		int g = gcd(sz(s), sz(t));
		int l = (sz(s) / g) * (sz(t) / g) * g;

		for(int i = 1; i <= l / p; i++) cout << sP;			
		cout << '\n';
	}
}

int main() {
	fastio

	int T;
	cin >> T;

	while(T--) solve();

	return 0;
}
