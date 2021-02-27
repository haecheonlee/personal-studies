#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 4e2 + 10;

int a[MAX_N];

void solve() {
	int N; cin >> N;
	for(int i = 1; i <= 4 * N; i++) cin >> a[i];
	sort(a + 1, a + 1 + 4 * N);
	
	int sticks = 0;
	for(int i = 2; i <= N * 4; i += 2) {
		if(a[i] == a[i - 1]) sticks++;
	}
	
	if(sticks / 2 != N) {
		cout << "NO" << '\n';
		return;
	}

	int area = a[4 * N] * a[1];
	for(int i = 2; i <= N; i++) {
		int L = i * 2, R = (4 * N) - (i * 2) + 1;
		if(a[L] * a[R] != area) {
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
