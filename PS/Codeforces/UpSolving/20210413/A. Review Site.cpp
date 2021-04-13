#include <iostream>

using namespace std;

void solve() {
	int N; cin >> N;
	int a[N];
	for(int i = 0; i < N; i++) cin >> a[i];
	
	int ans = 0;
	for(int i = 0; i < N; i++) {
		if(a[i] == 1 || a[i] == 3) ans++;
	}
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
