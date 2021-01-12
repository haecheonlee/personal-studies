#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1e2 + 1;

int N, M, T;
char board[MAX][MAX];
int d[MAX][MAX][16];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int sx, sy, ex, ey;

int go(int x, int y, int t) {
	if(t == T) return x == ex && y == ey;
	
	int& ret = d[x][y][t];
	if(ret != -1) return ret;
	ret = 0;
	
	for(int k = 0; k < 4; k++) {
		int nx = dx[k] + x;
		int ny = dy[k] + y;
		
		if(1 <= nx && nx <= N && 1 <= ny && ny <= M) {
			if(board[nx][ny] == '.') ret += go(nx, ny, t + 1);
		}
	}
	
	return ret;
}

int main() {
	cin >> N >> M >> T;
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) 
			cin >> board[i][j];
	}

	cin >> sx >> sy >> ex >> ey;
	
	memset(d, -1, sizeof(d));
	cout << go(sx, sy, 0) << '\n';
	
	return 0;
}
