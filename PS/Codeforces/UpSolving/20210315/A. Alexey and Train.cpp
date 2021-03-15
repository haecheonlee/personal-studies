#include <iostream>

using namespace std;

const int MAX_N = 1e2 + 1;

int a[MAX_N], b[MAX_N], t[MAX_N], dep[MAX_N], arr[MAX_N];

void solve() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) cin >> a[i] >> b[i];
	for(int i = 1; i <= N; i++) cin >> t[i];
	for(int i = 1; i <= N; i++) arr[i] = dep[i] = 0;
	
	for(int i = 1; i <= N; i++) {
		arr[i] = dep[i - 1] + a[i] - b[i - 1] + t[i];
		dep[i] = max(arr[i] + (b[i] - a[i] + 1) / 2, b[i]);
	}
	cout << arr[N] << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
