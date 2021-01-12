#include <iostream>

using namespace std;

const int MAX_N = 5 * 1e4 + 1;

int a[MAX_N];

void solve() {
	int N;
	cin >> N;
	
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	int x = a[1], y = a[2], z = a[N];
	if(x + y <= z) cout << 1 << ' ' << 2 << ' ' << N << '\n';
	else cout << -1  << '\n';
}

int main() {
	int T;
	cin >> T;
	
	while(T--) solve();

	return 0;
}
