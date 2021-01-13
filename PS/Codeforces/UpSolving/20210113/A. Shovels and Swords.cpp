#include <iostream>

using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;
	
	cout << min(a, min(b, (a + b) / 3)) << '\n';
}

int main() {
	int T;
	cin >> T;
	
	while(T--) solve();

	return 0;
}
