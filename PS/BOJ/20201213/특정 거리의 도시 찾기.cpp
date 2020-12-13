#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

const int MAX = 3e5 + 1;

vector<int> G[MAX];
int d[MAX];

int main() {
	fastio
	
	int N, M, K, X;
	cin >> N >> M >> K >> X;
	
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		
		G[u].push_back(v);
	}

	memset(d, -1, sizeof(d));
	queue<int> q;
	q.push(X);
	d[X] = 0;
	
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		
		for(auto& y : G[x]) {
			if(d[y] == -1) {
				d[y] = d[x] + 1;
				q.push(y);
			}
		}
	}
	
	vector<int> ans;
	for(int i = 1; i <= N; i++) {
		if(d[i] == K) ans.push_back(i);
	}
	
	if(ans.empty()) {
		cout << -1;
	} else {
		for(auto& x : ans) cout << x << '\n';
	}
	
	return 0;
}
