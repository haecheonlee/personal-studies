#include <iostream>

using namespace std;

void solve() {
	int N; cin >> N;
	long long a[N];
	for(int i = 0; i < N; i++) cin >> a[i];
	
	long long p = 0;
	for(long long i = 0; i < N; i++) {
		a[i] += p;
		if(a[i] >= i) {
			p = (a[i] - i);
		} else {
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
