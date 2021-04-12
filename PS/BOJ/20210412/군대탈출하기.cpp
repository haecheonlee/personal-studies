#include <iostream>
#include <queue>
#include <cstring>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

#define fi first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAX_N = 1e2 + 10;
const int INF = 1e9 + 10;

int N, M;
int a[MAX_N][MAX_N];
int d[MAX_N][MAX_N][2];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main() {
	fastio
	
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++) 
			cin >> a[i][j];
		
	memset(d, 0x3f, sizeof(d));
	priority_queue<pair<pii, pii>, vector<pair<pii, pii>>, greater<pair<pii, pii>>> pq;
	pq.push({{a[1][1], 0}, {1, 1}});
	d[1][1][0] = a[1][1];
	
	while(!pq.empty()) {
		int l = pq.top().fi.fi;
		int s = pq.top().fi.sc;
		int x = pq.top().sc.fi;
		int y = pq.top().sc.sc;
		pq.pop();
		
		if(d[x][y][s] < l) continue;
		for(int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if(1 <= nx && nx <= N && 1 <= ny && ny <= M) {
				int nl = max(l, a[nx][ny]);
				
				if(d[nx][ny][s] > nl) {
					d[nx][ny][s] = nl;
					pq.push({{nl, s}, {nx, ny}});
				}
				
				if(s == 0 && !(nx == N && ny == M)) {
					int nnx = nx + dx[k];
					int nny = ny + dy[k];
					
					if(1 <= nnx && nnx <= N && 1 <= nny && nny <= M) {
						nl = max(a[nnx][nny], l);
						if(d[nnx][nny][1] > l) {
							d[nnx][nny][1] = nl;
							pq.push({{nl, 1}, {nnx, nny}});
						}	
					}
					
				}
			}
		}
	}
	
	cout << min(d[N][M][0], d[N][M][1]) << '\n';
	
	return 0;
}
