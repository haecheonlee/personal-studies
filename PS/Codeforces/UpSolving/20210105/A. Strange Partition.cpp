#include <iostream>

using namespace std;

void solve() {
	int N, K;
	cin >> N >> K;
	
	int a[N];
	for(int i = 0; i < N; i++) cin >> a[i];
	
	long long mx = 0, mn = 0;
	for(int i = 0; i < N; i++) mx += (a[i] + K - 1) / K, mn += a[i];
	
	cout << (mn + K - 1) / K << ' ' << mx << '\n';
}

int main() {
	int T;
	cin >> T;
	
	while(T--) solve();

	return 0;
}
