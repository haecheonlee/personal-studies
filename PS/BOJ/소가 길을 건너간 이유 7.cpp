#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;
typedef pair<int,int> pii;

const int MAX = 1e2 + 1;

int a[MAX][MAX];
ll d[MAX][MAX][3];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

int main() {
	int N, K;
	cin >> N >> K;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) cin >> a[i][j];
	}

	memset(d, 0x3f, sizeof(d));	
	priority_queue<pair<pli,pii>> q;
	q.push({{0,0}, {0,0}});
	d[0][0][0] = 0;
	
	while(!q.empty()) {
		ll c = -q.top().first.first;	// cost
		int v = q.top().first.second;	// no of visited
		int x = q.top().second.first;
		int y = q.top().second.second;
		q.pop();
		
		if(d[x][y][v] < c) continue;
		for(int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if(0 <= nx && nx < N && 0 <= ny && ny < N) {
				ll nc = c + K;
				int nv = v + 1;
				
				if(nv == 3) {
					nc += a[nx][ny];
					nv = 0;
				}
				
				if(d[nx][ny][nv] > nc) {
					d[nx][ny][nv] = nc;
					q.push({{-nc, nv}, {nx, ny}});
				}
			}
		}
	}
	
	ll ans = -1;
	for(int v = 0; v < 3; v++) {
		if(ans == -1 || ans > d[N - 1][N - 1][v]) ans = d[N - 1][N - 1][v];
	}
	cout << ans;

	return 0;
}
