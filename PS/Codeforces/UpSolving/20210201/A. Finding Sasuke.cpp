#include <iostream>

using namespace std;

void solve() {
	int N; cin >> N;
	int a[N + 1];
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	int b[N + 1];
	for(int i = 1; i <= N / 2; i++) {
		int sum = a[i] * a[N - i + 1];
		b[i] = sum / a[i];
		b[N - i + 1] = -sum / a[N - i + 1];
	}
	
	for(int i = 1; i <= N; i++) cout << b[i] << ' ';
	cout << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
