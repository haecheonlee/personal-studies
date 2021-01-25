#include <iostream>

using namespace std;

void solve() {
	int N;
	cin >> N;

	for(int i = 0; i <= N / 2020; i++) {
		if(N - (i * 2020) >= 0 && (N - (i * 2020)) % 2021 == 0) {
			cout << "Yes" << '\n';
			return;
		}
	}
	
	cout << "No" << '\n';
}

int main() {
	int T;
	cin >> T;
	
	while(T--) solve();
	
	return 0;
}
