#include <iostream>

using namespace std;

void solve() {
	int a, b; cin >> a >> b;
	if(a > b) swap(a, b);
	if((a + b) % 3 == 0 && a * 2 >= b) cout << "Yes" << '\n';
	else cout << "No" << '\n';
}

int main() {
	int T;
	cin >> T;

	while(T--) solve();

	return 0;
}
