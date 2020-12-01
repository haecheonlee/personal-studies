/* Judge's solution */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e5 + 1;

vector<int> G[MAX];
int d[MAX], ans[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, M, Q, K;
	cin >> N >> M >> Q >> K;
	
	memset(d, -1, sizeof(d));
	queue<int> q;
	for(int i = 0; i < Q; i++) {
		int x;
		cin >> x;
		
		d[x] = 0;
		q.push(x);
	}
	
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
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
	
	int k = 1, j = 1;
	while(k < MAX) {
		for(int i = k; i < k + j * K; i++) if(i < MAX) ans[i] = j;
		k += j * K;
		j++;
	}
	
	for(int i = 1; i <= N; i++) cout << ans[d[i]] << ' ';
	
	return 0;
}
