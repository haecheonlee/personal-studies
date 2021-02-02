#include <iostream>

using namespace std;

void solve() {
	int N; cin >> N;
	int E = (N + 3) / 4;
	
	for(int i = 0; i < N - E; i++) cout << "9";
	for(int i = 0; i < E; i++) cout << "8";
	cout << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
