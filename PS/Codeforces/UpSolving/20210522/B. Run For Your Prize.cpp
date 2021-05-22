#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 10;

int a[MAX_N];

int main() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) cin >> a[i];

	int ans = 0;
	int L = 1, R = 1e6;
	for(int i = 1; i <= N; i++) {
		int t = min(a[i] - L, R - a[i]);
		ans = max(ans, t);
	}
	cout << ans << '\n';
	
	return 0;
}
