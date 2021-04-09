#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

void solve() {
	ll N; cin >> N;
	while(1) {
		ll sum = 0;
		string s = to_string(N);
		for(auto& x : s) sum += (x - '0');
		
		ll r = gcd(N, sum);
		if(r != 1) {
			cout << N << '\n';
			break;
		}
		N++;
	}
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
