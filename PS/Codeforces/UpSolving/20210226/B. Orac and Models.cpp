#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 1;

int a[MAX_N], d[MAX_N];

void solve() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		d[i] = 1;
	}
	
	int ans = 0;
	for(int i = 1; i <= N; i++) {
		for(int j = i + i; j <= N; j += i) {
			if(a[i] < a[j]) d[j] = max(d[j], d[i] + 1); 
		}
		ans = max(ans, d[i]);
	}
	
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
