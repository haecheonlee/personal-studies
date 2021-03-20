#include <iostream>

using namespace std;

typedef long long ll;

void solve() {
	int N; cin >> N;
	
	ll sum = 0, L = 0, used = 0;
	for(int i = 0; i < N; i++) {
		ll x; cin >> x;
		if(x < 0) {
			used += min(L, abs(x));
			L = max(0LL, L + x);
		} else if(x > 0) {
			L += x;
			sum += x;
		}
		
	}
	
	cout << sum - used << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
