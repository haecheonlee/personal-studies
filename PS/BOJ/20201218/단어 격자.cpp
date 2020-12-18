#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAX = 2e2 + 1;

int N, M, L;
string board[MAX];
string s;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
ll d[MAX][MAX][MAX / 2];

bool chk(int x, int y) {
	return 0 <= x && x < N && 0 <= y && y < M;
}

ll go(int x, int y, int l) {
	if(l == L) return 1;
	
	ll& ret = d[x][y][l];
	if(ret != -1) return ret;
	ret = 0;
	
	for(int k = 0; k < 8; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		
		if(chk(nx, ny) && board[nx][ny] == s[l]) ret += go(nx, ny, l + 1);
	}
	
	return ret;
}

int main() {
	cin >> N >> M >> L;
	for(int i = 0; i < N; i++) cin >> board[i];
	cin >> s;

	memset(d, -1, sizeof(d));

	ll ans = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(board[i][j] == s[0]) ans += go(i, j, 1);
		}
	}
	cout << ans << '\n';
	
	return 0;
}
