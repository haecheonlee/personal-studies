#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define fi first
#define sc second
#define sz(x) (int)(x.size())

using namespace std;

typedef pair<int,int> pii;

const int MAX = 50;

int N, M, sx, sy;
int cost[3];
int check[MAX][MAX];
int d[MAX][MAX][1 << 4];
vector<vector<pii>> dir{
	{ {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2} },
	{ {-1, -1}, {-1, 1}, {1, -1}, {1, 1} },
	{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} }
};

int main() {
	cin >> N;
	for(int i = 0; i < 3; i++) cin >> cost[i];
	cin >> sx >> sy >> M;
	
	memset(check, -1, sizeof(check));
	for(int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		
		check[x][y] = i;
	}
	
	
	memset(d, 0x3f, sizeof(d));
	priority_queue<pair<pii, pii>> pq;
	int state = (check[sx][sy] != -1 ? (1 << check[sx][sy]) : 0);
	pq.push({{0, state}, {sx, sy}});
	
	while(!pq.empty()) {
		int c = -pq.top().fi.fi;
		int s = pq.top().fi.sc;
		int x = pq.top().sc.fi;
		int y = pq.top().sc.sc;
		pq.pop();

		if(s + 1 == (1 << M)) {
			cout << c << '\n';
			break;
		}
		
		if(d[x][y][s] < c) continue;
		for(int i = 0; i < 3; i++) {
			if(i == 0) {
				// knight
				for(int k = 0; k < sz(dir[i]); k++) {
					int nx = x + dir[i][k].fi;
					int ny = y + dir[i][k].sc;
				
					if(0 <= nx && nx < N && 0 <= ny && ny < N) {
						int nc = c + cost[i];
						int ns = s;
						if(check[nx][ny] != -1) ns |= (1 << check[nx][ny]);
						
						if(d[nx][ny][ns] > nc) {
							d[nx][ny][ns] = nc;
							pq.push({{-nc, ns}, {nx, ny}});
						}
					}
				}				
			} else {
				// Bishop, Rook
				for(int k = 0; k < sz(dir[i]); k++) {
					int nx = x + dir[i][k].fi;
					int ny = y + dir[i][k].sc;
					int nc = c + cost[i];
					
					while(0 <= nx && nx < N && 0 <= ny && ny < N) {
						int ns = s;
						if(check[nx][ny] != -1) ns |= (1 << check[nx][ny]);
						
						if(d[nx][ny][ns] > nc) {
							d[nx][ny][ns] = nc;
							pq.push({{-nc, ns}, {nx, ny}});
						}
						
						nx += dir[i][k].fi, ny += dir[i][k].sc;
					}
				}
			}
		}
	}
	
	return 0;
}
