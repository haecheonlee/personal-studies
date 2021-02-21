#include <iostream>
#include <vector>
#include <queue>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

const int MAX_N = 2e5 + 1;

int N, R, P;
vector<pii> G[MAX_N];
int out[MAX_N], d[MAX_N];

void bfs() {
	queue<pii> q;
	q.push({R, -1});
	d[R] = 0;
	
	while(!q.empty()) {
		int x = q.front().fi;
		int px = q.front().sc;
		q.pop();
	
		if(P == 0 && (out[x] >= 2 || out[x] == 0)) P = x; 	
		for(auto& nxt : G[x]) {
			int y = nxt.fi, c = nxt.sc;
			if(y != px) {
				out[y]--;
				d[y] = d[x] + c;
				q.push({y, x});
			}
		}
	}
}

int main() {
	fastio
	cin >> N >> R;
	
	for(int i = 0 ; i < N - 1; i++) {
		int u, v, d; cin >> u >> v >> d;
		
		out[u]++, out[v]++;
		G[u].push_back({v, d});
		G[v].push_back({u, d});
	}
	
	bfs();
	
	int dist = 0;
	for(int i = 1; i <= N; i++)
		if(out[i] == 0) 
			dist = max(dist, d[i]);
	
	cout << d[P] << ' ' << dist - d[P] << '\n';;
	
	return 0;
}
