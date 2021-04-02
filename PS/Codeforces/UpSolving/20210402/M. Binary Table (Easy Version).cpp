#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e2 + 10;

char board[MAX][MAX];

int countOne(int x, int y) {
	int cnt = 0;
	for(int i = x; i <= x + 1; i++) 
		for(int j = y; j <= y + 1; j++)
			if(board[i][j] == '1')
				cnt++;
				
	return cnt;
}

void solve() {
	int N, M; cin >> N >> M;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			cin >> board[i][j];

	vector<vector<int>> ans;	
	for(int i = 0; i < N - 1; i++) {
		for(int j = 0; j < M - 1; j++) {
			int cnt = countOne(i, j);
			if(cnt == 0) continue;
			if(cnt == 4) {
				cnt = 1;
				vector<int> p;
				int one = 0;
				for(int x = i; x <= i + 1; x++) {
					for(int y = j; y <= j + 1; y++) {
						if(one < 3) {
							board[x][y] = '0';
							p.push_back(x + 1); p.push_back(y + 1);
							one++;
						}
					}
				}
				ans.push_back(p);
			}
			
			for(int k = 3 - cnt + 1; k >= 1; k--) {
				vector<int> p;
				if(k == 1) {
					// find three of '1'
					for(int x = i; x <= i + 1; x++) {
						for(int y = j; y <= j + 1; y++) {
							if(board[x][y] == '1') {
								board[x][y] = '0';
								p.push_back(x + 1); p.push_back(y + 1);
							}
						}
					}
				} else {
					// find two of '0', and one of '1'
					int zero = 0, one = 0;
					for(int x = i; x <= i + 1; x++) {
						for(int y = j; y <= j + 1; y++) {
							if(board[x][y] == '0') {
								if(zero < 2) {
									board[x][y] = '1', zero++;
									p.push_back(x + 1); p.push_back(y + 1);
								}
							} else if(board[x][y] == '1') {
								if(one < 1) {
									board[x][y] = '0', one++;
									p.push_back(x + 1); p.push_back(y + 1);
								}
							}
						}
					}
				}
				if(p.size()) ans.push_back(p);
			}
		}
	}
	
	cout << ans.size() << '\n';
	for(auto& p : ans) {
		for(auto& pp : p) cout << pp << ' ';
		cout << '\n';		
	}
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
