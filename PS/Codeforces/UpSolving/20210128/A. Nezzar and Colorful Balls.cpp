#include <iostream>

using namespace std;

const int MAX_N = 1e2 + 1;

int a[MAX_N];

void solve() {
	int N; cin >> N;
	int ans = 0, cnt = 0;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		if(a[i] != a[i - 1]) cnt = 1;
		else cnt++;

		ans = max(ans, cnt);
	}
	cout << ans << '\n';
}

int main() {
	int T;
	cin >> T;

	while(T--) solve();

	return 0;
}
