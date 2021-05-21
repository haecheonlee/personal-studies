/* reference: codeplus/beakjoon */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
		vector<pair<int,int>> from(N, make_pair(-1, -1));
		
		queue<int> q;
		q.push(source);
		check[source] = 1;
		
		while(!q.empty()) {
			int x = q.front();
			q.pop();
			
			for(int i = 0; i < G[x].size(); i++) {
				if(check[G[x][i]->to] || G[x][i]->capacity <= 0) continue;
				check[G[x][i]->to] = 1;
				from[G[x][i]->to] = make_pair(x, i);
				q.push(G[x][i]->to);
			}
		}
		
		if(!check[sink]) return 0;
		
		int x = sink;
		int c = G[from[x].first][from[x].second]->capacity;
		while(from[x].first != -1) {
			if(c > G[from[x].first][from[x].second]->capacity)
				c = G[from[x].first][from[x].second]->capacity;
			x = from[x].first;
		}
		
		x = sink;
		while(from[x].first != -1) {
			Edge* e = G[from[x].first][from[x].second];
			e->capacity -= c;
			e->rev->capacity += c;
			x = from[x].first;
		}
		return c;
	}
	
	int flow() {
		int ans = 0;
		while(true) {
			int f = bfs();
			if(f == 0) break;
			ans += f;
		}
		return ans;
	}
};

const int MAX = 1e2 + 10;

char board[MAX][MAX];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int in_node(int x, int y, int m) {
	return 2 * (x * m + y);
}

int out_node(int x, int y, int m) {
	return in_node(x, y, m) + 1;
}

int main() {
	int N, M; cin >> N >> M;
	int sx, sy, ex, ey;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> board[i][j];
			
			if(board[i][j] == 'K') sx = i, sy = j;
			else if(board[i][j] == 'H') ex = i, ey = j;
		}
	}

	int INF = 1e9;
	MaximumFlow mf(2 * (N * M), out_node(sx, sy, M), in_node(ex, ey, M));
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(board[i][j] == '#') continue;
			mf.add_edge(in_node(i, j, M), out_node(i, j, M), 1);
			
			for(int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				
				if(0 <= nx && nx < N && 0 <= ny && ny < M) {
					if(board[nx][ny] != '#') 
						mf.add_edge(out_node(i, j, M), in_node(nx, ny, M), INF);	
				}
			}
		}
	}
	
	int ans = mf.flow();
	if(ans >= INF) ans = -1;
	cout << ans << '\n';

	return 0;
}
