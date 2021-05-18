#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct MaximumFlow {
	struct Edge {
		int to;
		int capacity;
		Edge* rev;
		Edge(int to, int capacity) : to(to), capacity(capacity) {}
	};
	
	int N;
	int source, sink;
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
			if(G[x][i]->capacity > 0) {
				int nc = G[x][i]->capacity;
				if(c != 0 && c < nc) nc = c;
				
				int f = dfs(G[x][i]->to, nc);
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
		while(true) {
			fill(check.begin(), check.end(), false);
			int f = dfs(source, 0);
			if(f == 0) break;
			ans += f;
		}
		return ans;
	}
};

int main() {
	int N, M; cin >> N >> M;
	int source = 0, sink = N + M + 1;
	
	MaximumFlow mf(sink + 1, source, sink);
	for(int i = 1; i <= N; i++) {
		int k; cin >> k;
		while(k--) {
			int to; cin >> to; to += N;
			mf.add_edge(i, to, 1);
		}
	}
	
	// source to cow
	for(int i = 1; i <= N; i++) mf.add_edge(source, i, 1);
	
	// barn to sink
	for(int i = N + 1; i <= N + M + 1; i++) mf.add_edge(i, sink, 1);
	
	cout << mf.flow() << '\n';
	
	return 0;
}
