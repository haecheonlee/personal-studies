#include <iostream>
#include <cmath>

using namespace std;

void solve() {
	int N; cin >> N;
	int k = log2(N);
	
	int ans = 1;
	for(int i = 0; i < k; i++) ans *= 2;
	cout << ans - 1 << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
