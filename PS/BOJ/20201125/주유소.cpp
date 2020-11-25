/* reference: https://justicehui.github.io/koi/2018/12/15/BOJ13308/ */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAX = 2501;

int N, M;
vector<pii> G[MAX];
ll price[MAX];
bool chk[MAX][MAX];

ll dijkstra() {
	priority_queue<pair<ll, pii>> q;
	q.push({0, {1, price[1]}});
	
	while(!q.empty()) {
		ll c = -q.top().first;
		int x = q.top().second.first;
		ll p = q.top().second.second;
		q.pop();
		
		if(chk[x][p]) continue;
		if(x == N) return c;
		
		chk[x][p] = 1;
		for(auto& nxt : G[x]) {
			ll nc = c + (nxt.second * p);
			int y = nxt.first;
			
			int np = min(p, price[y]);
			if(chk[y][np] == false) q.push({ -nc, { y,  np } });
		}
	}
	
	return -1;
}

int main() {
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++) cin >> price[i];
	for(int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		
		G[u].push_back({v, c});
		G[v].push_back({u, c});
	}
	
	cout << dijkstra();
	
	return 0;
}
