#include <iostream>

using namespace std;

void solve() {
	int N; cin >> N;
	
	if(N <= 30) {
		cout << "NO" << '\n';
	} else {
		int d = N - 30;
		cout << "YES" << '\n';
		if(d != 6 && d != 10 && d != 14) {
			cout << 6 << ' ' << 10 << ' ' << 14 << ' ' << d << '\n';
		} else {
			cout << 6 << ' ' << 10 << ' ' << 15 << ' ' << N - 31 << '\n';
		}
	}
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
