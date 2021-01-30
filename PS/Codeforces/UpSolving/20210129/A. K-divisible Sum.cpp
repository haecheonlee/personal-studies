#include <iostream>

using namespace std;

typedef long long ll;

void solve() {
	int n, k; cin >> n >> k;
	
	ll s = (n + k - 1) / k * k;
	cout << (s + n - 1) / n << '\n';
}

int main() {
	int T;
	cin >> T;

	while(T--) solve();

	return 0;
}
