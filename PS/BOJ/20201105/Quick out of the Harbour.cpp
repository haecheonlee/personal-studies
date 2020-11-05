#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 5e2 + 1;

char a[MAX][MAX];
int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};
int d[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;
	
	while(T--) {
		int N, M, K;
		cin >> N >> M >> K;
		
		int sx, sy;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				cin >> a[i][j];
				
				if(a[i][j] == 'S') sx = i, sy = j;	
			}
		}
		
		memset(d, 0x3f, sizeof(d));
		priority_queue<pair<int,pii>> q;
		q.push({0, {sx, sy}});
		d[sx][sy] = 0;
		
		while(!q.empty()) {
			int c = -q.top().first;
			int x = q.top().second.first;
			int y = q.top().second.second;
			q.pop();
			
			if(d[x][y] < c) continue;
			for(int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				
				if(0 <= nx && nx < N && 0 <= ny && ny < M) {
					if(a[nx][ny] == '#') continue;
					
					int nc = c + (a[nx][ny] == '@' ? K + 1 : 1);
					if(d[nx][ny] > nc) {
						d[nx][ny] = nc;
						q.push({-nc, {nx, ny}});
					}
				}
			}
		}
		
		int ans = 1e9;
		// top
		for(int j = 0; j < M; j++) if(d[0][j] != '#') ans = min(ans, d[0][j]);
		
		// bottom
		for(int j = 0; j < M; j++) if(d[0][j] != '#') ans = min(ans, d[N -1][j]);
		
		// left
		for(int i = 0; i < M; i++) if(d[i][0] != '#') ans = min(ans, d[i][0]);
		
		// right
		for(int i = 0; i < M; i++) if(d[i][M - 1] != '#') ans = min(ans, d[i][M - 1]);
		
		cout << ans + 1<< '\n';
	}

	return 0;
}
