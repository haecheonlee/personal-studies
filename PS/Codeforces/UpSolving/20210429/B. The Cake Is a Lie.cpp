#include <iostream>

using namespace std;

const int MAX = 1e2 + 10;

int d[MAX][MAX];

void solve() {
	int N, M, K; cin >> N >> M >> K;
	cout << (d[N][M] == K ? "YES" : "NO") << '\n';
}

int main() {
	for(int i = 1; i <= 100; i++) {
		d[i][1] = i - 1;
		for(int j = 2; j <= 100; j++) d[i][j] = d[i][j - 1] + i;
	}
	
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
