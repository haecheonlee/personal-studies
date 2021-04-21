/* reference: SecondThread */

#include <iostream>

using namespace std;

const int MAX_N = 2e3 + 10;

int a[MAX_N];

void solve() {
	int N; cin >> N;
	
	int xr = 0;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		xr ^= a[i];
	}
	
	if(xr == 0) {
		cout << "YES" << '\n';
	} else {
		int L = a[1];
		for(int i = 2; i <= N; i++) {
			int R = a[i];
			for(int j = i + 1; j <= N; j++) {
				if(L == R && R == xr) {
					cout << "YES" << '\n';
					return;
				}
				R ^= a[j];
			}
			L ^= a[i];
		}
		cout << "NO" << '\n';
	}
	
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
