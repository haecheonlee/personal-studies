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
	int px, py; cin >> px >> py;
	string s;
	cin >> s;

	int L = 0, R = 0, U = 0, D = 0;
	for(int i = 0; i < sz(s); i++) {
		if(s[i] == 'L') L++;
		else if(s[i] == 'R') R++;
		else if(s[i] == 'U') U++;
		else if(s[i] == 'D') D++;
	}
	
	if(((px <= 0 && px >= -L) || (px >= 0 && px <= R)) && ((py <= 0 && py >= -D) || (py >= 0 && py <= U))) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int main() {
	fastio
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
