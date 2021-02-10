#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 1;

int a[MAX_N], b[MAX_N];

void solve() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) cin >> a[i];
	for(int i = 1; i <= N; i++) cin >> b[i];
	
	int k = -1;
	for(int i = 1; i <= N; i++) {
		if(k == -1) {
			if(a[i] == b[i]) continue;
			if(a[i] > b[i]) {
				cout << "NO" << '\n';
				return;
			}
			k = b[i] - a[i];
		} else {
			if(k > 0) {
				if(a[i] == b[i]) {
					k = 0;
				} else if(a[i] + k != b[i]) {
					cout << "NO" << '\n';
					return;
				}
			} else {
				if(a[i] != b[i]) {
					cout << "NO" << '\n';
					return;
				}
			}
		}
	}
	
	cout << "YES" << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
