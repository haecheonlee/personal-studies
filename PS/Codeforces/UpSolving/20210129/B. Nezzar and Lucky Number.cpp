#include <iostream>

using namespace std;

void solve() {
	int N, d; cin >> N >> d;

	for(int i = 0; i < N; i++) {
		int a;
		cin >> a;

		if(a % d == 0) {
			cout << "YES" << '\n';
		} else {
			if(a >= d * 10) {
				cout << "YES" << '\n';
			} else {
				while(a > 10 && a % d != 0)
					a -= 10;
				
				cout << (a % d == 0 ? "YES" : "NO") << '\n';
			}
		}
	}
}

int main() {
	int T;
	cin >> T;

	while(T--) solve();

	return 0;
}
