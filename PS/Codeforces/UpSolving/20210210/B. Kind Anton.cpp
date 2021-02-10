#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 1;

int a[MAX_N], b[MAX_N];

void solve() {
	int N; cin >> N;
	for(int i = 0; i < N; i++) cin >> a[i];
	for(int i = 0; i < N; i++) cin >> b[i];
	
	bool minus = false, plus = false;
	for(int i = 0; i < N; i++) {
		if(a[i] != b[i]) {
			if((a[i] > b[i] && !minus) || (a[i] < b[i] && !plus)) {
				cout << "NO" << '\n';
				return;
			}
		}
		
		if(a[i] > 0) plus = 1;
		else if(a[i] < 0) minus = 1;
	}
	
	cout << "YES" << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
