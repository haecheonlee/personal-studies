#include <iostream>
#include <queue>
#include <cstring>

#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e2 + 1;
const int INF = 1e9;

// 0: right, 1: left, 2: down, 3: up

int N;
int a[MAX][MAX];
int d[MAX][MAX][21][5];
int dx[] = {0, 0, 1, -1};		
int dy[] = {1, -1, 0, 0};

bool chk(int x, int y) {
	return x >= 1 && x <= N && y >= 1 && y <= N;
}

int main() {
	cin >> N;
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			cin >> a[i][j];
			if(a[i][j] == 0) a[i][j] = INF;
		}
	}
	
	memset(d, 0x3f, sizeof(d));
	queue<pair<pii, pii>> q;
	d[1][1][0][4] = 0;
	q.push({{1, 1}, {0, 4}});
	
	while(!q.empty()) {
		int x = q.front().fi.fi;
		int y = q.front().fi.sc;
		int cost = q.front().sc.fi;
		int prev = q.front().sc.sc;
		q.pop();
		
		// current time
		int ret = d[x][y][cost][prev];
		for(int k = 0; k < 4; k++) {
			int nx = x, ny = y;
			
			if(k == prev) {
				// going to same direction
				bool is_possible = true;
				for(int i = 0; i < cost; i++) {
					nx += dx[k], ny += dy[k];
					if(!chk(nx, ny) || a[nx][ny] <= ret) { is_possible = false; break; } 
				}
				
				nx += dx[k], ny += dy[k];
				if(is_possible && chk(nx, ny) && a[nx][ny] > ret + 1) {
					if(d[nx][ny][cost + 1][k] > ret + 1) {
						d[nx][ny][cost + 1][k] = ret + 1;
						q.push({{nx, ny}, {cost + 1, k}});
					}
				}
			} else {
				nx += dx[k], ny += dy[k];
				if(chk(nx, ny) && a[nx][ny] > ret + 1) {
					if(d[nx][ny][1][k] > ret + 1) {
						d[nx][ny][1][k] = ret + 1;
						q.push({{nx, ny}, {1, k}});
					}
				}
			}
		}
	}
	
	int ans = INF;
	for(int i = 1; i <= 20; i++) {
		for(int k = 0; k < 4; k++) ans = min(ans, d[N][N][i][k]);
	}

	if(ans == INF) cout << "Fired" << '\n';
	else cout << ans << '\n';
	
	return 0;
}
