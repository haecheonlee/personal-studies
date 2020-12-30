#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 50;
const int MAX_K = 1e2 + 5e1 + 1;

int N, M, K;
int ans = 0;
char board[MAX][MAX];
char d[MAX][MAX][MAX_K][MAX_K];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
// 0: L, 1: R, 2: U, 3: D

int cw(int dir) {
	if(dir == 0) return 2;
	else if(dir == 1) return 3;
	else if(dir == 2) return 1;
	else return 0;
}

int ccw(int dir) {
	if(dir == 0) return 3;
	else if(dir == 1) return 2;
	else if(dir == 2) return 0;
	else return 1;
}

int convert(char dir) {
	if(dir == 'L') return 0;
	else if(dir == 'R') return 1;
	else if(dir == 'U') return 2;
	else return 3;
}

char go(int x, int y, int l, int r) {
	if(ans == 1) return 1;
	if(x < 0 || x >= N || y < 0 || y >= M) return 0;
	if(x == N - 1 && y == M - 1) return ans = 1;
	
	char& ret = d[x][y][l][r];
	if(ret != -1) return ret;
	ret = 0;
	
	int k = convert(board[x][y]);
	ret = max(ret, go(x + dx[k], y + dy[k], l, r));
	
	if(r > 0) {
		int nk = k;
		for(int kk = 1; kk <= 3 && r - kk >= 0; kk++) {
			nk = cw(nk);
			ret = max(ret, go(x + dx[nk], y + dy[nk], l, r - kk));
		}
	}
	
	if(l > 0) {
		int nk = k;
		for(int kk = 1; kk <= 3 && l - kk >= 0; kk++) {
			nk = ccw(nk);
			ret = max(ret, go(x + dx[nk], y + dy[nk], l - kk, r));
		}
	}
	
	return ret;
}

int main() {
	cin >> N >> M >> K;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) cin >> board[i][j];
	}
	
	memset(d, -1, sizeof(d));
	go(0, 0, K, K);
	cout << (ans == 1 ? "Yes" : "No") << '\n';

	return 0;
}
