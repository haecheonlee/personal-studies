#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

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
	vector<pii> from;
	vector<int> distance;
	int INF = 1e9;
	
	MCMF(int N, int source, int sink) : N(N), source(source), sink(sink) {
		G.resize(N);
		check.resize(N);
		from.resize(N);
		distance.resize(N);
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
		fill(all(distance), INF);
		fill(all(from), make_pair(-1, -1));
		
		queue<int> q;
		q.push(source);
		distance[source] = 0;
		
		while(!q.empty()) {
			int x = q.front();
			q.pop();

			check[x] = false;
			for(int i = 0; i < G[x].size(); i++) {
				int y = G[x][i]->to;
				int nc = distance[x] + G[x][i]->cost;
				
				if(G[x][i]->capacity > 0 && distance[y] > nc) {
					distance[y] = nc;
					from[y] = make_pair(x, i);
					if(!check[y]) {
						check[y] = 1;
						q.push(y);
					}
				}
			}
		}
		
		if(distance[sink] == INF) return false;
		
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
		total_cost += (c * distance[sink]);
		return true;
	}
	
	pii flow() {
		int total_flow = 0, total_cost = 0;
		while(spfa(total_flow, total_cost));
		return make_pair(total_flow, total_cost);
	}
};

const int MAX = 1e2 + 10;

int C[MAX][MAX], D[MAX][MAX];

int main() {
	int N, M; cin >> N >> M;
	
	MCMF mcmf(N + M + 2, 0, N + M + 1);
	for(int i = 1; i <= N; i++) {
		int x; cin >> x;
		mcmf.add_edge_from_source(i, x, 0);
	}
	
	for(int i = 1; i <= M; i++) {
		int x; cin >> x;
		mcmf.add_edge_to_sink(i + N, x, 0);
	}

	for(int i = 1; i <= M; i++) for(int j = 1; j <= N; j++) cin >> C[i][j];
	for(int i = 1; i <= M; i++) for(int j = 1; j <= N; j++) cin >> D[i][j];
	
	for(int i = 1; i <= M; i++) for(int j = 1; j <= N; j++) 
		mcmf.add_edge(j, i + N, C[i][j], D[i][j]);
	
	auto ans = mcmf.flow();
	cout << ans.fi << '\n' << ans.sc << '\n';

	return 0;
}
