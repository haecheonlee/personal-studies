/* reference: https://hello70825.tistory.com/79 */

#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e3 + 1;

int N, M;
int a[MAX][MAX];
int d[MAX][MAX];
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int dijkstra(int sx, int sy, int ex, int ey) {
	memset(d, 0x3f, sizeof(d));
	
	deque<pii> q;
	q.push_front({sx, sy});
	d[sx][sy] = 0;
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();
		
		if(x == ex && y == ey) return d[x][y];
		for(int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if(1 <= nx && nx <= N && 1 <= ny && ny <= M) {
				int nc = d[x][y];
				if(a[x][y] == k) {
					if(d[nx][ny] > d[x][y]) {
						d[nx][ny] = d[x][y];
						q.push_front({nx, ny});
					}
				} else {
					if(d[nx][ny] > d[x][y] + 1) {
						d[nx][ny] = d[x][y] + 1;
						q.push_back({nx,ny});
					}
				}
				
			}
		}
	}
	
	return -1;
}

int main() {
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) scanf("%1d", &a[i][j]);
	}
	
	int T;
	cin >> T;
	
	while(T--) {
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
	
		printf("%d \n", dijkstra(sx, sy, ex , ey));	
	}

	return 0;
}
