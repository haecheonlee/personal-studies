#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e2 + 1;
const int MAX_M = 1e3 + 1;

char board[MAX_N][MAX_M];

void solve() {
	int N, M, x, y;
	cin >> N >> M >> x >> y;
	
	// update the price of y
	if(x * 2 < y) y = x * 2;
	
	vector<int> a[N];
	for(int i = 0; i < N; i++) {
		int p = -1;
		for(int j = 0; j < M; j++) {
			cin >> board[i][j];
			
			if(board[i][j] == '.' && p == -1) p = j;
			else if(board[i][j] == '*' && p != -1) a[i].push_back(j - p), p = -1;
		}
		
		if(p != -1) a[i].push_back(M - p);
	}

	int ans = 0;
	for(int i = 0; i < N; i++) {
		for(auto& L : a[i]) {
			if(L % 2 == 0) ans += min(L * x, L / 2 * y);
			else ans += min(L * x, L / 2 * y + x);
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
