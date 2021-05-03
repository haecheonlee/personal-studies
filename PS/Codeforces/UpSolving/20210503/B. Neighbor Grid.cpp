#include <iostream>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void solve() {
	int N, M; cin >> N >> M;
	int a[N][M];
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) cin >> a[i][j];
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			int cnt = 0;
			for(int k = 0; k < 4; k++) {
				int ii = i + dx[k];
				int jj = j + dy[k];
					
				if(0 <= ii && ii < N && 0 <= jj && jj < M) cnt++;
			}

			if(a[i][j] == 0) {
				a[i][j] = cnt;
			} else {
				if(a[i][j] > cnt) {
					cout << "NO" << '\n';
					return;
				} else {
					a[i][j] = cnt;
				}
			}
		}
	}
	
	cout << "YES" << '\n';
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) cout << a[i][j] << ' ';
		cout << '\n';
	}
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
