/* reference: Rebro */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 5e2 + 2;

int a[MAX][MAX];

void solve() {
	int N, M; cin >> N >> M;
	int ans = 0;
	
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= N; i++) {
		string s; cin >> s;
		for(int j = 0; j < M; j++) if(s[j] == '*') a[i][j + 1] = 1;
	}
	
	for(int i = N; i >= 1; i--) {
		for(int j = 1; j <= M; j++) {
			if(a[i][j] == 1) a[i][j] += min(a[i + 1][j - 1], min(a[i + 1][j], a[i + 1][j + 1]));
			ans += a[i][j];
		}
	}
	cout << ans << '\n';
}

int main() {
	int T;
	cin >> T;
	
	while(T--) solve();

	return 0;
}
