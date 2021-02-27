/* editorial */

#include <iostream>

using namespace std;

void solve() {
	int N; cin >> N;
	long long sum = 0, XOR = 0;
	for(int i = 1; i <= N; i++) {
		int x; cin >> x;
		sum += x;
		XOR ^= x;
	}
	
	cout << 2 << '\n';
	cout << XOR << ' ' << sum + XOR << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
