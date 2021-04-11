#include <iostream>
#include <vector>
#include <deque>

#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e2 + 10;

int N, M;
char board[MAX][MAX];
int d[MAX][MAX][3];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs(int sx, int sy, int idx) {
	deque<pii> dq;
	dq.push_front({sx, sy});
	d[sx][sy][idx] = 0;
	
	while(!dq.empty()) {
		int x = dq.front().fi;
		int y = dq.front().sc;
		dq.pop_front();
		
		for(int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if(0 <= nx && nx <= N + 1 && 0 <= ny && ny <= M + 1) {
				if(board[nx][ny] == '*') continue;
				if(d[nx][ny][idx] == -1) {
					if(board[nx][ny] == '#') {
						d[nx][ny][idx] = d[x][y][idx] + 1;
						dq.push_back({nx, ny});
					} else {
						d[nx][ny][idx] = d[x][y][idx];
						dq.push_front({nx, ny});
					}
				}
			}
		}
	}
}

void solve() {
	cin >> N >> M;
	
	// reset
	for(int i = 0; i <= N + 1; i++) {
		for(int j = 0; j <= M + 1; j++) {
			board[i][j] = '.';
			for(int k = 0; k < 3; k++) d[i][j][k] = -1;
		}
	}
	
	vector<pii> p;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			cin >> board[i][j];
			if(board[i][j] == '$') p.push_back({i, j});
		}
	}
	
	p.push_back({0, 0});
	for(int i = 0; i < 3; i++) bfs(p[i].fi, p[i].sc, i);
	
	int ans = -1;
	for(int i = 0; i <= N + 1; i++) {
		for(int j = 0; j <= M + 1; j++) {
			if(d[i][j][0] == -1 || d[i][j][1] == -1 || d[i][j][2] == -1) continue;
			int sum = d[i][j][0] + d[i][j][1] + d[i][j][2];
			
			if(board[i][j] == '#') sum -= 2;
			if(ans == -1 || ans > sum) ans = sum;
		}
	}
	cout << ans << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();

	return 0;
}
