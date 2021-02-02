/* editorial */

#include <iostream>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX 1e9
#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

const int MAX_N = 2e5 + 1;

int cnt[4];
pii p[MAX_N];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void solve() {
	int N, X, Y; cin >> N >> X >> Y;
	
	for(int i = 0; i < N; i++) cin >> p[i].fi >> p[i].sc;

	pii ans;
	int total = 0;
	for(int k = 0; k < 4; k++) {
		cnt[k] = 0;
		
		int nx = X + dx[k], ny = Y + dy[k];
		if(nx < 0 || nx > MAX || ny < 0 || ny > MAX) continue;

		for(int i = 0; i < N; i++) {
			int xL = min(p[i].fi, X), xR = max(p[i].fi, X);
			int yL = min(p[i].sc, Y), yR = max(p[i].sc, Y);
			if(xL <= nx && nx <= xR && yL <= ny && ny <= yR) cnt[k]++;
		}

		if(cnt[k] > total) {
			ans = make_pair(nx, ny);
			total = cnt[k];
		}
	}

	cout << total << '\n';
	cout << ans.fi << ' ' << ans.sc << '\n';
}

int main() {
	fastio

	solve();

	return 0;
}
