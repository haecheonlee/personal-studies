/* reference: JusticeHui, Minimax-algorithm */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 1e3 + 1;

int N;
int a[MAX_N];
int dp[MAX_N][MAX_N][2];

int minimax(int L, int R, bool flag) {
	if(L >= R) return (flag) ? 0 : a[L];
	
	int& ret = dp[L][R][flag];
	if(ret != -1) return ret;
	
	if(!flag) {
		// GW
		return ret = max(minimax(L + 1, R, !flag) + a[L], minimax(L, R - 1, !flag) + a[R]);
	} else {
		// MW
		return ret = min(minimax(L + 1, R, !flag), minimax(L, R - 1, !flag));
	}
}

void solve() {
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	memset(dp, -1, sizeof(dp));
	cout << minimax(1, N, 0) << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
