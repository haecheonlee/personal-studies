#include <iostream>

using namespace std;

const int MAX_N = 2e2 + 10;

int a[MAX_N];

void solve() {
	int N; cin >> N;
	
	int start = -1;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		if(a[i] == 1) start = i;	
	}
	
	// cw
	bool ans = 1;
	int idx = start;
	for(int i = 1; i <= N; i++) {
		if(a[idx] != i) {
			ans = 0;
			break;
		} else {
			idx++;
			if(idx > N) idx = 1;
		}
	}
	
	// ccw
	bool ans2 = 1;
	idx = start;
	for(int i = 1; i <= N; i++) {
		if(a[idx] != i) {
			ans2 = 0;
			break;
		} else {
			idx--;
			if(idx < 1) idx = N;
		}
	}
	
	cout << (ans || ans2 ? "YES" : "NO") << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
