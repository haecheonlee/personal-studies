#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

struct MaximumFlow {
	struct Edge {
		int to, capacity;
		Edge* rev;
		Edge(int to, int capacity) : to(to), capacity(capacity) { }
	};
	
	int N, source, sink;
	vector<vector<Edge*>> G;

	MaximumFlow(int N, int source, int sink) : N(N), source(source), sink(sink) {
		G.resize(N);
	}
	
	void add_edge_from_source(int v, int cap) {
		add_edge(source, v, cap);
	}
	
	void add_edge_to_sink(int u, int cap) {
		add_edge(u, sink, cap);
	}
	
	void add_edge(int u, int v, int cap) {
		Edge* ori = new Edge(v, cap);
		Edge* rev = new Edge(u, 0);
		
		ori->rev = rev;
		rev->rev = ori;
		
		G[u].push_back(ori);
		G[v].push_back(rev);
	}
	
	int bfs() {
		vector<bool> check(N, false);
		vector<pii> from(N, make_pair(-1, -1));
		
		queue<int> q;
		check[source] = 1;
		q.push(source);
		
		while(!q.empty()) {
			int x = q.front();
			q.pop();
			
			for(int i = 0; i < G[x].size(); i++) {
				int to = G[x][i]->to;
				int capacity = G[x][i]->capacity;

				if(!check[to] && capacity > 0) {
					check[to] = 1;
					from[to] = make_pair(x, i);
					q.push(to);
				}
			}
		}
		
		if(!check[sink]) return 0;
		
		int x = sink;
		int c = G[from[x].fi][from[x].sc]->capacity;
		
		while(from[x].fi != -1) {
			int nc = G[from[x].fi][from[x].sc]->capacity;
			if(c > nc) c = nc;
			x = from[x].fi;
		}
		
		x = sink;
		while(from[x].fi != -1) {
			Edge* edge = G[from[x].fi][from[x].sc];
			edge->capacity -= c;
			edge->rev->capacity += c;
			x = from[x].fi;
		}
		return c;
	}
	
	int flow() {
		int ans = 0;
		while(1) {
			int f = bfs();
			if(f == 0) break;
			ans += f;
		}
		return ans;
	}
};

int main() {
	int N, M; cin >> N >> M;
	
	MaximumFlow mf(N + M + 2, 0, N + M + 1);
	for(int i = 1; i <= N; i++) {
		// source to person
		int x; cin >> x;
		mf.add_edge_from_source(i, x);
	}
	
	for(int i = 1; i <= M; i++) {
		// bookstore to sink
		int x; cin >> x;
		mf.add_edge_to_sink(i + N, x);
	}
	
	for(int i = 1; i <= M; i++) {
		for(int j = 1; j <= N; j++) {
			// person to bookstore
			int x; cin >> x;
			if(x > 0) mf.add_edge(j, i + N, x);
		}
	}
	
	cout << mf.flow() << '\n';

	return 0;
}
