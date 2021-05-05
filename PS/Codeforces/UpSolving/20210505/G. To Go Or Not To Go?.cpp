#include <iostream>
#include <queue>
#include <vector>

#define fi first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 2e3 + 10;
const ll INF = 1e18;

ll N, M, W;
int a[MAX][MAX];
ll d1[MAX][MAX], d2[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void go(int sx, int sy, ll d[MAX][MAX]) {
	priority_queue<pair<ll, pii>> pq;
	pq.push({0, {sx, sy}});
	d[sx][sy] = 0;
	
	while(!pq.empty()) {
		ll c = -pq.top().fi;
		int x = pq.top().sc.fi;
		int y = pq.top().sc.sc;
		pq.pop();

		if(d[x][y] < c) continue;
		for(int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if(0 <= nx && nx < N && 0 <= ny && ny < M) {
				if(a[nx][ny] == -1) continue;
				if(d[nx][ny] > d[x][y] + 1) {
					d[nx][ny] = d[x][y] + 1;
					pq.push({-d[nx][ny], {nx, ny}});
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M >> W;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> a[i][j];
			d1[i][j] = d2[i][j] = INF;
		}
	}
	
	go(0, 0, d1);
	go(N - 1, M - 1, d2);

	ll ans = INF, min1 = INF, min2 = INF;
	if(d1[N - 1][M - 1] != INF) ans = d1[N - 1][M - 1] * W;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(a[i][j] > 0 && d1[i][j] != INF) {
				min1 = min(min1, a[i][j] + d1[i][j] * W);
			}
		}
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(a[i][j] > 0  && d2[i][j] != INF) {
				min2 = min(min2, a[i][j] + d2[i][j] * W);
			}
		}
	}

	ans = min(ans, min1 + min2);
	cout << (ans >= INF ? -1 : ans) << '\n';

	return 0;
}
