/* reference: editorial */

#include <iostream>

using namespace std;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	
	int k = (a + b + c);
	if(k % 9 == 0) {
		k /= 9;
		cout << (a >= k && b >= k && c >= k ? "YES" : "NO") << '\n';
	} else {
		cout << "NO\n";
	}
}

int main() {
	int T;
	cin >> T;
	
	while(T--) solve();
	
	return 0;
}
