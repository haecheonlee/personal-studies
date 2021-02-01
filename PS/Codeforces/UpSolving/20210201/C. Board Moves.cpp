#include <iostream>

using namespace std;

const int MAX_N = 5e5 + 1;

long long d[MAX_N];

void solve() {
	int N; cin >> N;
	cout << d[N] << '\n';
}

int main() {
	d[1] = 0;
	for(int i = 3; i < MAX_N; i += 2) {
		long long p = i / 2;
		d[i] = d[i - 2] + (p * p * 8);
	}
	
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
