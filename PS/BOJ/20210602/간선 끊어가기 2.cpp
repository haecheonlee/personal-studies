#include <iostream>
#include <vector>

using namespace std;

struct MaximumFlow {
	struct Edge {
		int to, capacity;
		Edge* rev;
		Edge(int to, int capacity) : to(to), capacity(capacity) {
			
		}
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
		for(auto& nxt : G[x]) {
			int y = nxt->to;
			int nc = nxt->capacity;
			
			if(nc > 0) {
				if(c != 0 && c < nc) nc = c;
				int f = dfs(y, nc);
				
				if(f) {
					nxt->capacity -= f;
					nxt->rev->capacity += f;
					
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

struct E {
	int a, b, c;
	E(int a, int b, int c) : a(a), b(b), c(c) {
	}
};

int main() {
	int N, M; cin >> N >> M;
	
	vector<E> e;
	for(int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		e.push_back({a, b, c});
	}
	int s, t; cin >> s >> t;
	
	MaximumFlow mf(N, s - 1, t - 1);
	for(int i = 0; i < M; i++) {
		mf.add_edge(e[i].a - 1, e[i].b - 1, e[i].c);
		mf.add_edge(e[i].b - 1, e[i].a - 1, e[i].c);	
	}
	cout << mf.flow() << '\n';
	
	return 0;
}
