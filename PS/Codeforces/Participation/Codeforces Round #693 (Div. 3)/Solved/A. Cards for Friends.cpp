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

void solve() {
	int W, H, N;
	cin >> W >> H >> N;

	if(N == 1) {
		cout << "YES\n";
		return;
	} 
	
	ll total = 0, w = 0, h = 0;
	while(W && W % 2 == 0) w++, W /= 2;
	while(H && H % 2 == 0) h++, H /= 2;

	total = (1 << w) * (1 << h);
	cout << (total >= N ? "YES" : "NO") << '\n';
}

int main() {
	int T;
	cin >> T;

	while(T--) solve();

	return 0;
}
