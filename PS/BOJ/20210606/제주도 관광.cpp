/* reference: codeplus/baekjoon */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

struct MCMF {
	struct Edge {
		int to, capacity, cost;
		Edge* rev;
		Edge(int to, int capacity, int cost) : to(to), capacity(capacity), cost(cost) {
			
		}
	};
	
	int N, source, sink;
	vector<vector<Edge*>> G;
	vector<bool> check;
	vector<pii> from;
	vector<int> d;
	int INF = 1e9;
	
	MCMF(int N, int source, int sink) : N(N), source(source), sink(sink) {
		G.resize(N);
		check.resize(N);
		from.resize(N);
		d.resize(N);
	}
	
	void add_edge(int u, int v, int capacity, int cost) {
		Edge* ori = new Edge(v, capacity, cost);
		Edge* rev = new Edge(u, 0, -cost);
		
		ori->rev = rev;
		rev->rev = ori;
		
		G[u].push_back(ori);
		G[v].push_back(rev);
	}
	
	void add_edge_from_source(int v, int capacity, int cost) {
		add_edge(source, v, capacity, cost);
	}
	
	void add_edge_to_sink(int u, int capacity, int cost) {
		add_edge(u, sink, capacity, cost);
	}
	
	bool spfa(int& flow, int& cost) {
		fill(check.begin(), check.end(), false);
		fill(from.begin(), from.end(), make_pair(-1, -1));
		fill(d.begin(), d.end(), INF);
		
		queue<int> q;
		d[source] = 0;
		q.push(source);
		
		while(!q.empty()) {
			int x = q.front();
			q.pop();
			
			check[x] = 0;
			
			for(int i = 0; i < G[x].size(); i++) {
				int y = G[x][i]->to;
				int nc = d[x] + G[x][i]->cost;
		
				if(G[x][i]->capacity > 0 && d[y] > nc) {
					d[y] = nc;
					from[y] = make_pair(x, i);
					
					if(!check[y]) {
						check[y] = 1;
						q.push(y);
					}
				}
			}
		}
		
		if(d[sink] == INF) return false;
		
		int x = sink;
		int c = G[from[x].fi][from[x].sc]->capacity;
		
		while(from[x].fi != -1) {
			int nc = G[from[x].fi][from[x].sc]->capacity;
			if(c > nc) c = nc;
			x = from[x].fi;
		}
		
		x = sink;
		while(from[x].fi != -1) {
			Edge* e = G[from[x].fi][from[x].sc];
			e->capacity -= c;
			e->rev->capacity += c;
			x = from[x].fi;
		}
		
		flow += c;
		cost += d[sink] * c;
		
		return true;
	}
	
	pii flow() {
		int flow = 0, cost = 0;
		while(spfa(flow, cost));
		return make_pair(flow, cost);
	}
};

int in_node(int x) {
	return x * 2;
}

int out_node(int x) {
	return x * 2 + 1;
}

void solve() {
	int N, M; cin >> N >> M;

	MCMF mcmf(N * 2 + 4, N * 2, N * 2 + 1);
	for(int i = 0; i < M; i++) {
		int u, v; cin >> u >> v;
		u--, v--;
		mcmf.add_edge(out_node(u), in_node(v), 1, 0);
	}
	
	for(int i = 0; i < N; i++) {
		mcmf.add_edge(in_node(i), out_node(i), 1, -1);
		mcmf.add_edge(N * 2 + 2, in_node(i), 1, 0);	// source
		mcmf.add_edge(out_node(i), N * 2 + 3, 1, 0);	// sink
	}
	
	mcmf.add_edge_from_source(N * 2 + 2, 2, 0);	// super-source
	mcmf.add_edge_to_sink(N * 2 + 3, 2, 0);		// super-sink
	cout << -mcmf.flow().sc << '\n';
}

int main() {
	int T; cin >> T;
	while(T--) solve();
	
	return 0;
}
