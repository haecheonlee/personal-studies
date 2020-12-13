#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

const int MAX = 1e5 + 1;

vector<int> G[MAX];
int d[MAX];

int main() {
	fastio
	
	int N, M;
	cin >> N >> M;
	
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	memset(d, -1, sizeof(d));
	queue<int> q;
	q.push(1);
	d[1] = 0;
	
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		
		for(auto& v : G[u]) {
			if(d[v] == -1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	
	cout << d[N] - 1 << '\n';

	return 0;
}
