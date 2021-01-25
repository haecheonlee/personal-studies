#include <iostream>

using namespace std;

void solve() {
	long long N;
	cin >> N;
	
	while(N != 1) {
		if(N % 2 == 0) N /= 2;
		else {
			cout << "YES" << '\n';
			return;
		}
	}
	
	cout << "NO" << '\n';
}

int main() {
	int T;
	cin >> T;
	
	while(T--) solve();

	return 0;
}
