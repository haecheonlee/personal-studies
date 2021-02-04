#include <iostream>

using namespace std;

void solve() {
	int N; cin >> N;
	if(N == 1) {
		cout << -1 << '\n';
		return;
	}
	
	cout << 2;
	for(int i = 0; i < N - 1; i++) cout <<3;
	cout << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
