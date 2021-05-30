#include <iostream>
#include <vector>

using namespace std;

const int MAX_D = 1e2 + 10;

int a[MAX_D];

struct MaximumFlow {
	struct Edge {
		int to, capacity;
		Edge* rev;
		Edge(int to, int capacity) : to(to), capacity(capacity) { }
	};
	
	int N, source, sink;
	vector<vector<Edge*>> G;
	vector<bool> check;

	MaximumFlow(int N, int source, int sink) : N(N), source(source), sink(sink) {
		G.resize(N);
		check.resize(N);
	}
	
	void add_edge(int u, int v, int cap) {
		Edge* ori = new Edge(v, cap);
		Edge* rev = new Edge(u, 0);
		
		ori->rev = rev;
		rev->rev = ori;
		
		G[u].push_back(ori);
		G[v].push_back(rev);
	}
	
	int dfs(int x, int c) {
		if(check[x]) return 0;
		check[x] = 1;
		if(x == sink) return c;
		
		for(int i = 0; i < G[x].size(); i++) {
			int y = G[x][i]->to;
			int nc = G[x][i]->capacity;

			if(nc > 0) {
				if(c != 0 && c < nc) nc = c;
				
				int f = dfs(y, nc);
				if(f) {
					G[x][i]->capacity -= f;
					G[x][i]->rev->capacity += f;
					return f;
				}
			}
		}
		
		return 0;
	}
	
	int flow() {
		int ans = 0;
		while(1) {
			fill(check.begin(), check.end(), false);
			int f = dfs(source, 0);
			if(f == 0) break;
			ans += f;
		}
		return ans;
	}
};

int main() {
	int N, K, D; cin >> N >> K >> D;

	MaximumFlow mf(N + D + 2, 0, N + D + 1);
	for(int i = 1; i <= D; i++) cin >> a[i];
	
	for(int i = 1; i <= N; i++) {
		int q; cin >> q;
		while(q--) {
			int x; cin >> x;
			mf.add_edge(i, x + N, 1);
		}
	}

	// source to people
	for(int i = 1; i <= N; i++) mf.add_edge(0, i, K);
	
	// food to sink
	for(int i = 1; i <= D; i++) {
		mf.add_edge(i + N, N + D + 1, a[i]);
	}
	
	cout << mf.flow() << '\n';

	return 0;
}
