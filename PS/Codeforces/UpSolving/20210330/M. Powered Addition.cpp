/* reference: https://www.youtube.com/watch?v=ZXGVq6sjQl0&ab_channel=Gravekper */

#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 10;

ll a[MAX_N], b[MAX_N];

void solve() {
	int N; cin >> N;
	
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		b[i] = 0;
	}
	
	ll mxB = 0;
	for(int i = 2; i <= N; i++) {
		if(a[i] < a[i - 1] + b[i - 1]) {
			b[i] = a[i - 1] + b[i - 1] - a[i];
			mxB = max(mxB, b[i]);
		}
	}
	
	ll ans = 0;
	for(ans = 0; (1LL << ans) <= mxB; ans++);
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
