/* reference: codeplus/beakjoon */
/* Edmond-Karp */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct MaximumFlow {
	struct Edge {
		int to;
		int capacity;
		Edge* rev;
		Edge(int to, int capacity) : to(to), capacity(capacity) {}
	};
	
	int N;
	int source, sink;
	vector<vector<Edge*>> graph;
	MaximumFlow(int N, int source, int sink) : N(N), source(source), sink(sink) {
		graph.resize(N);
	}
	
	void add_edge(int u, int v, int cap) {
		Edge* ori = new Edge(v, cap);
		Edge* rev = new Edge(u, 0);
		ori->rev = rev;
		rev->rev = ori;
		
		graph[u].push_back(ori);
		graph[v].push_back(rev);
	}
	
	int bfs() {
		vector<bool> check(N, false);
		vector<pair<int,int>> from(N, make_pair(-1, -1));
		
		queue<int> q;
		check[source] = true;
		q.push(source);
		
		while(!q.empty()) {
			int x = q.front();
			q.pop();
			
			for(int i = 0; i < graph[x].size(); i++) {
				if(graph[x][i]->capacity > 0 && !check[graph[x][i]->to]) {
					check[graph[x][i]->to] = true;
					from[graph[x][i]->to] = make_pair(x, i);
					q.push(graph[x][i]->to);
				}
			}
		}
		
		if(!check[sink]) return 0;
		int x = sink;
		int c = graph[from[x].first][from[x].second]->capacity;
		while(from[x].first != -1) {
			if(c > graph[from[x].first][from[x].second]->capacity) { 
				c = graph[from[x].first][from[x].second]->capacity;
			}
			x = from[x].first;
		}
		x = sink;
		while(from[x].first != -1) {
			Edge* edge = graph[from[x].first][from[x].second];
			edge->capacity -= c;
			edge->rev->capacity += c;
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

int node(const char& c) {
	if(c & (1 << 5)) return c - 'a' + 26;
	return c - 'A';
}

int main() {
	int M; cin >> M;
	MaximumFlow mf(52, 0, 'Z' - 'A');
	
	for(int i = 0; i < M; i++) {
		char from, to; int f;
		cin >> from >> to >> f;
		
		int u = node(from), v = node(to);
		mf.add_edge(u, v, f);
		mf.add_edge(v, u, f);
	}
	cout << mf.flow() << '\n';
	
	return 0;
}
