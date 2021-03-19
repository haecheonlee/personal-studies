#include <iostream>

using namespace std;

const int MAX = 1e2 + 1;

char ans[MAX][MAX];

void solve() {
	int N, M; cin >> N >> M;
	
	char x;
	for(int i = 1; i <= N; i++) {
		if(i == 1) x = 'B';
		else x = (ans[i - 1][1] == 'B' ? 'W' : 'B');
		
		for(int j = 1; j <= M; j++) {
			ans[i][j] = x;
			x = (x == 'B' ? 'W' : 'B');
		}
	}
	
	if(!(N & 1) && !(M & 1)) ans[N][1] = 'B';
	else if(!(N & 1) || !(M & 1)) ans[N][M] = 'B';
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) cout << ans[i][j];
		cout << '\n';
	}
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
