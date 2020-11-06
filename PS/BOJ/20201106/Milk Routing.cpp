#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 5e2 + 1;

vector<pair<int,pii>> a[MAX];
pii d[MAX];

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	
	for (int i = 0; i < M; i++) {
		int u, v, l, c;
		cin >> u >> v >> c >> l;
		
		a[u].push_back({v, {c,l}});
		a[v].push_back({u, {c,l}});
	}

	memset(d, 0x3f, sizeof(d));
	priority_queue<pair<pii,int>> q;
	q.push({{0,1e6 + 1}, 1});
	d[1].first = 0, d[1].second=1e6 + 1;
	
	while(!q.empty()) {
		int c = -q.top().first.first;
		int l = q.top().first.second;
		int x = q.top().second;
		q.pop();

		if(d[x].first + K / d[x].second < c + K / l) continue;
		for(auto& next : a[x]) {
			int y = next.first;
			int nc = next.second.first + c;
			int nl = min(next.second.second, l);
			
			if(d[y].first + K / d[y].second > nc + K / nl) {
				d[y].first = nc;
				d[y].second = nl;
				q.push({{-nc, nl}, y});
			}
		}
	}
	
	cout << d[N].first + K / d[N].second;
	
	return 0;
}
