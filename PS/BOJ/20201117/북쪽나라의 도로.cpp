#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e4 + 1;

vector<pii> a[MAX];
int d[MAX];

int bfs(int sx) {
	memset(d, -1, sizeof(d));
	
	queue<int> q;
	q.push(sx);
	d[sx] = 0;
	
	int ex = -1, mx = 0;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		
		if(d[x] > mx) mx = d[x], ex = x;
		for(auto& next : a[x]) {
			int y = next.first;
			int c = next.second;
			
			if(d[y] == -1) {
				d[y] = d[x] + c;
				q.push(y);
			}
		}
	}
	
	return ex;
}

int main() {
	int u, v, k;
	
	while(cin >> u >> v >> k) {
		a[u].push_back({v, k});
		a[v].push_back({u, k});
	}
	
	int p1 = bfs(1);
	int p2 = bfs(p1);
	
	int ans = 0;
	for(int i = 1; i <= MAX; i++) ans = max(ans, d[i]);
	cout << ans << '\n';

	return 0;
}
