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
	
	bool spfa(int& total_flow, int& total_cost) {
		fill(check.begin(), check.end(), false);
		fill(d.begin(), d.end(), INF);
		fill(from.begin(), from.end(), make_pair(-1, -1));
		
		queue<int> q;
		d[source] = 0;
		q.push(source);
		
		while(!q.empty()) {
			int x = q.front();
			q.pop();
			check[x] = 0;
			
			for(int i = 0; i < G[x].size(); i++) {
				int y = G[x][i]->to;
				int nc = G[x][i]->cost + d[x];
				
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
		
		int x  = sink;
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
		int flow = 0, cost = 0;
		while(spfa(flow, cost));
		return make_pair(flow, cost);
	}
};

const int MAX_N = 60;

int in[MAX_N], out[MAX_N];

int main() {
	int N; cin >> N;
	for(int i = 1; i <= N; i++) cin >> in[i];
	for(int i = 1; i <= N; i++) cin >> out[i];
	int T, F; cin >> T >> F;
	
	MCMF mcmf1(N * 2 + 2, 0, N * 2 + 1);	// min-cost
	MCMF mcmf2(N * 2 + 2, 0, N * 2 + 1);	// max-cost
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(in[i] < out[j]) {
				int S = out[j] - in[i];
				if(S < T) {
					int x = T - S;
					mcmf1.add_edge(i, j + N, 1, min(x * x, F));
					mcmf2.add_edge(i, j + N, 1, -min(x * x, F));
				} else {
					mcmf1.add_edge(i, j + N, 1, 0);
					mcmf2.add_edge(i, j + N, 1, 0);
				}
			}
		}
	}
	
	// source to in
	// out to sink
	for(int i = 1; i <= N; i++) {
		// source
		mcmf1.add_edge_from_source(i, 1, 0);
		mcmf2.add_edge_from_source(i, 1, 0);
		
		// sink
		mcmf1.add_edge_to_sink(i + N, 1, 0);
		mcmf2.add_edge_to_sink(i + N, 1, 0);
	}
	
	auto ans1 = mcmf1.flow(), ans2 = mcmf2.flow();
	if(ans1.fi != N || ans2.fi != N) {
		cout << -1 << '\n';
	} else {
		cout << ans1.sc << ' ' << -ans2.sc << '\n';
	}

	return 0;
}
