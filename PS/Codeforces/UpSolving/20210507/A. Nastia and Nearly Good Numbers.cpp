#include <iostream>

using namespace std;

void solve() {
	long long A, B; cin >> A >> B;
	long long x = A * B;
	
	if(B == 1) {
		cout << "NO" << '\n';
	} else {
		cout << "YES" << '\n';
		cout << x << ' ' << A << ' ' << x + A << '\n'; 
	}
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
