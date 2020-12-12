#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1e2 + 1;

int N, M;
vector<int> G[MAX];
int d[MAX];

int bfs(int sx) {
	memset(d, -1, sizeof(d));
	
	queue<int> q;
	q.push(sx);
	d[sx] = 0;
	
	int far = 0, idx = sx;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		
		if(far < d[x]) far = d[x], idx = x;
		for(auto& y : G[x]) {
			if(d[y] == -1) {
				d[y] = d[x] + 1;
				q.push(y);
			}
		}
	}
	
	return idx;
}

int main() {
	cin >> N >> M;
	
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	int s = bfs(1);
	int e = bfs(s);
	
	bool ans = (s != e);
	for(int i = 1; i <= N; i++) if(d[i] == -1) ans = 0; 
	
	if(ans) cout << (d[e] != -1 && d[e] <= 6 ? "Small World!" : "Big World!");
	else cout << "Big World!";
	
	return 0;
}
