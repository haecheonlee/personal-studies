/* reference: editorial */

#include <iostream>

using namespace std;

void solve() {
	int N; cin >> N;
	int a[N + 10];
	for(int i = 1; i <= N; i++) cin >> a[i];

	bool flag = 1;
	for(int i = 1; i <= N; i++) if(a[i] != i) flag = 0;

	int ans = 2;
	if(flag) ans = 0;
	else if(a[1] == 1 || a[N] == N) ans = 1;
	else if(a[1] == N && a[N] == 1) ans = 3;
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
