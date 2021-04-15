/* editorial */

#include <iostream>

using namespace std;

void solve() {
	int a, b, c; cin >> a >> b >> c;
	cout << "1";
	for(int i = 0; i < a - 1; i++) cout << "0";
	cout << ' ';
	for(int i = 0; i < b - c + 1; i++) cout << "1";
	for(int i = 0; i < c - 1; i++) cout << "0";
	cout << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
