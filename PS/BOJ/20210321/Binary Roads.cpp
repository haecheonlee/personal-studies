#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

const int MAX_N = 2e5 + 10;

vector<int> G[MAX_N][2];
int d[MAX_N][2];

int main() {
	fastio
	
	int N, M; cin >> N >> M;
	for(int i = 0; i < M; i++) {
		int u, v, k; cin >> u >> v >> k;
		G[u][k].push_back(v);
		G[v][k].push_back(u);
	}
	
	memset(d, -1, sizeof(d));
	queue<pii> q;
	q.push({0, 0}); q.push({0, 1});
	d[0][0] = d[0][1] = 0;
	
	while(!q.empty()) {
		int x = q.front().fi;
		int k = q.front().sc;
		q.pop();

		for(auto& y : G[x][k]) {
			int nk = 1 - k;
			if(d[y][nk] == -1) {
				d[y][nk] = d[x][k] + 1;
				q.push({y, nk});
			}
		}
	}
	
	int ans = -1;
	for(int k = 0; k < 2; k++)
		if(d[N - 1][k] != -1)
			if(ans == -1 || ans > d[N - 1][k])
				ans = d[N - 1][k];
	cout << ans << '\n';

	return 0;
}
