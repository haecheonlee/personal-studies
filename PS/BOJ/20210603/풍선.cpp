#include <iostream>
#include <vector>
#include <queue>

#define all(v) v.begin(), v.end()
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
		fill(all(check), false);
		fill(all(from), make_pair(-1, -1));
		fill(all(d), INF);
		
		queue<int> q;
		q.push(source);
		d[source] = 0;
		
		while(!q.empty()) {
			int x = q.front();
			q.pop();
			check[x] = false;
			
			for(int i = 0; i < (int)G[x].size(); i++) {
				int y = G[x][i]->to;
				int nc = d[x] + G[x][i]->cost;
				
				if(G[x][i]->capacity > 0 && d[y] > nc) {
					d[y] = nc;
					from[y] = make_pair(x, i);
					
					if(!check[y]) {
						check[y] = true;
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
	while(1) {
		int N, A, B; cin >> N >> A >> B;
		if(N == 0 && A == 0 && B == 0) break;
		
		// source: 0, sink: N + 3
		MCMF mcmf(N + 4, 0, N + 3);
		
		// A: 1, B: 2, team: 3 ~ N + 2
		for(int i = 0; i < N; i++) {
			int K, dA, dB; cin >> K >> dA >> dB;
			mcmf.add_edge(1, i + 3, K, dA);	// A Ballon
			mcmf.add_edge(2, i + 3, K, dB);	// B Ballon
			mcmf.add_edge_to_sink(i + 3, K, 0);	// sink
		}
		
		// source to ballon
		mcmf.add_edge_from_source(1, A, 0);
		mcmf.add_edge_from_source(2, B, 0);

		auto ans = mcmf.flow();
		cout << ans.sc << '\n';
	}
	
	return 0;
}
