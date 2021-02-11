#include <iostream>

using namespace std;

int main() {
	int l, r; cin >> l >> r;
	if(r - l >= 4) cout << 2 << '\n';
	else if(r - l == 3) {
		if(r % 3 == 0 && l % 3 == 0) cout << 3 << '\n';
		else cout << 2 << '\n';
	} else if(r - l == 2 || r - l == 1) {
		cout << 2 << '\n';
	} else {
		cout << l << '\n';
	}
	
	return 0;
}
