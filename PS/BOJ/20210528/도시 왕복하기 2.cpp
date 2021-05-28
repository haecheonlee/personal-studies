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
				int cap = G[x][i]->capacity;
				
				if(cap <= 0 || check[to]) continue;
				check[to] = 1;
				from[to] = make_pair(x, i);
				q.push(to);
			}
		}
		
		if(!check[sink]) return 0;
		
		int x = sink;
		int c = G[from[x].fi][from[x].sc]->capacity;
		while(from[x].fi != -1) {
			if(c > G[from[x].fi][from[x].sc]->capacity) 
				c = G[from[x].fi][from[x].sc]->capacity;
			x = from[x].fi;
		}
		
		x = sink;
		while(from[x].fi != -1) {
			Edge* edge = G[from[x].fi][from[x].sc];
			edge->capacity -= x;
			edge->rev->capacity += x;
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

const int INF = 1e9;

int main() {
	int N, M; cin >> N >> M;
	
	MaximumFlow mf(2 * N + 2, 2 * N, 2 * N + 1);
	for(int i = 0; i < M; i++) {
		int u, v; cin >> u >> v;
		u--, v--;
		mf.add_edge(u + N, v, 1);
		mf.add_edge(v + N, u, 1);
	}
	
	for(int i = 2; i < N; i++) mf.add_edge(i, i + N, 1);

	// multiple visit possible (0, 1)
	mf.add_edge(0, N, INF);
	mf.add_edge(1, N + 1, INF);

	// source to vIn(0)
	mf.add_edge(2 * N, 0, INF);
	
	// vOut(N - 1) to sink
	mf.add_edge(N + 1, 2 * N + 1, INF);

	cout << mf.flow() << '\n';

	return 0;
}
