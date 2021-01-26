/* reference: editorial */

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

void solve() {
	int A, B, K;
	cin >> A >> B >> K;
	
	vector<int> a(A), b(B);
	vector<pii> G(K);
	
	for(auto& g : G) cin >> g.first;
	for(auto& g : G) cin >> g.second;
	
	for(auto& g : G) {
		g.first--, g.second--;
		a[g.first]++, b[g.second]++;
	}
	
	ll ans = 0;
	for(auto& g : G) ans += K - a[g.first] - b[g.second] + 1;
	cout << ans / 2 << '\n';
}

int main() {
	int T;
	cin >> T;
	
	while(T--) solve();

	return 0;
}
