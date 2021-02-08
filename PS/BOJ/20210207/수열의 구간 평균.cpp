/* reference: surung9898 */

#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

map<ll,ll> sum;

int main() {
	ll N, K; cin >> N >> K;

	ll now = 0, ans = 0;
	for(int i = 1; i <= N; i++) {
		ll x; cin >> x;
		now += x;
	
		ll r = now - (K * i);

		ans += sum[r];
		sum[r]++;
	}
	cout << ans + sum[0] << '\n';
	
	return 0;
}
