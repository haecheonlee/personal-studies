#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 11;

int N, M, K;
char a[MAX][MAX];
int d[MAX][MAX][6];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void update(int& x, int& y) {
	if(x < 0) x = N - 1;
	if(x >= N) x = 0;
	
	if(y < 0) y = M - 1;
	if(y >= M) y = 0;
}

int go(string& s, int x ,int y, int now) {
	if(now == (int)s.size()) return 1;
	
	int& ret = d[x][y][now];
	if(ret != -1) return ret;
	ret = 0;
	
	for(int k = 0; k < 8; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		
		if(0 > nx || nx >= N || 0 > ny || ny >= M) update(nx, ny);
		if(s[now] == a[nx][ny]) ret += go(s, nx, ny, now + 1);
	}
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> M >> K;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) cin >> a[i][j];
	}

	while(K--) {
		string s;
		cin >> s;
		
		memset(d, -1, sizeof(d));
		int ans = 0;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(s[0] == a[i][j]) ans += go(s, i, j, 1);
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
