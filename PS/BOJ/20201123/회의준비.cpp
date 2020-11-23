#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 1e2 +1;

int N, M;
vector<int> a[MAX];
vector<int> g[MAX];
int p[MAX];
int d[MAX];

int Find(int x) {
	if(p[x] == x) return x;
	return p[x] = Find(p[x]);
}

void Union(int x, int y) {
	x = Find(p[x]);
	y = Find(p[y]);
	
	if(x != y) p[y] = x;
}

int bfs(int sx) {
	memset(d, -1, sizeof(d));
	
	int mx = 0;
	
	queue<int> q;
	q.push(sx);
	d[sx] = 0;
	
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		
		mx = max(mx, d[x]);
		for(auto& y : a[x]) {
			if(d[y] == -1) {
				d[y] = d[x] + 1;
				q.push(y);
			}
		}
	}
	
	return mx;
}

int main() {
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++) p[i] = i;
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		
		a[u].push_back(v);
		a[v].push_back(u);
		
		Union(u, v);
	}

	for(int i = 1; i <= N; i++) {
		int num = Find(p[i]);
		g[num].push_back(i);
	}
	
	vector<int> ans;	
	for(int i = 1; i <= N; i++) {
		if(g[i].empty()) continue;
		sort(g[i].begin(), g[i].end());
		
		int current_idx = -1, current_min = 1e9;
		for(auto& x : g[i]) {
			int k = bfs(x);
			if(current_min > k) current_idx = x, current_min = k;	
		}
		ans.push_back(current_idx);
	}
	sort(ans.begin(), ans.end());
	
	cout << (int)ans.size() << '\n';
	for(auto& x : ans) cout << x << '\n';
	
	return 0;
}
