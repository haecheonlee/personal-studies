#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

const int MAX = 2e4 + 1e2 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

vector<pii> a[MAX];
ll d[MAX][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M,B,K,Q;
	cin>>N>>M>>B>>K>>Q;
	
	// 1 ~ N: house
	// N + 1 ~ N + M: hospital
	// N + M + 1 ~ N + M + B: bridge
	
	for(int i = 0; i < K; i++) {
		int u,v,c;
		cin>>u>>v>>c;
		
		a[u].push_back({v,c});
		a[v].push_back({u,c});
	}

	// dijkstra
	memset(d, 0x3f, sizeof(d));	
	for(int i = 0; i < B; i++) {
		priority_queue<pli> q;
		q.push({0, N + M + 1 + i});
		d[N + M + 1 + i][i] = 0;
		
		while(!q.empty()) {
			ll c = -q.top().first;
			int x = q.top().second;
			q.pop();
			
			if(d[x][i] > c) continue;
			for(auto& next : a[x]) {
				int y = next.first;
				ll nc = c + next.second;
				
				if(d[y][i] > nc) {
					d[y][i] = nc;
					q.push({-nc, y});
				}
			}
		}
	}

	while(Q--) {
		int S,E;
		cin>>S>>E;
		
		ll ans = INF;
		for(int i = 0; i < B; i++) ans = min(ans, d[S][i] + d[E][i]);
		cout<<(ans == INF ? -1 : ans)<<'\n';
	}

	return 0;
}
