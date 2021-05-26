#include <iostream>
#include <vector>

using namespace std;

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
	
	bool dfs(int x, int c) {
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
	int N, P; cin >> N >> P;
	MaximumFlow mf(N, 0, 1);
	for(int i = 0; i < P; i++) {
		int u, v; cin >> u >> v;
		mf.add_edge(u - 1, v - 1, 1);
	}
	cout << mf.flow() << '\n';

	return 0;
}
