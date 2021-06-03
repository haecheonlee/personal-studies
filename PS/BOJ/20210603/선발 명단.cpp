#include <iostream>
#include <vector>
#include <queue>

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
	vector<int> d;
	vector<pii> from;
	int INF = 1e9;
	
	MCMF(int N, int source, int sink) : N(N), source(source), sink(sink) {
		G.resize(N);
		check.resize(N);
		d.resize(N);
		from.resize(N);
	}
	
	void add_edge(int u, int v, int cap, int cost) {
		Edge* ori = new Edge(v, cap, cost);
		Edge* rev = new Edge(u, 0, -cost);
		
		ori->rev = rev;
		rev->rev = ori;
		
		G[u].push_back(ori);
		G[v].push_back(rev);
	}
	
	void add_edge_from_source(int v, int cap, int cost) {
		add_edge(source, v, cap, cost);
	}
	
	void add_edge_to_sink(int u, int cap, int cost) {
		add_edge(u, sink, cap, cost);
	}
	
	bool spfa(int& total_flow, int& total_cost) {
		fill(check.begin(), check.end(), false);
		fill(d.begin(), d.end(), INF);
		fill(from.begin(), from.end(), make_pair(-1, -1));
		
		queue<int> q;
		q.push(source);
		d[source] = 0;
		
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
		
		total_flow += c;
		total_cost += (c * d[sink]);
		
		return true;
	}
	
	pii flow() {
		int total_flow = 0, total_cost = 0;
		while(spfa(total_flow, total_cost));
		return make_pair(total_flow, total_cost);
	}
};

int main() {
	int Q; cin >> Q;
	int N = 11;
	
	while(Q--) {
		// source: 0, sink: 23
		MCMF mcmf(N * 2 + 2, 0, N * 2 + 1);
		
		// player: 1 ~ 11, position: 12 ~ 22
		for(int i = 1; i <= N; i++) {
			// source to player
			mcmf.add_edge_from_source(i, 1, 0);
			for(int j = 1; j <= N; j++) {
				int x; cin >> x;
				if(x > 0) {
					mcmf.add_edge(i, j + N, 1, -x);
				}
			}
		}
		
		// position to sink
		for(int i = 1; i <= N; i++) mcmf.add_edge_to_sink(i + N, 1, 0);
		auto ans = mcmf.flow();
		cout << -ans.sc << '\n';
	}

	return 0;
}
