/* reference: codeplus/beakjoon */
/* Ford-Fulkerson(dfs) */

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
		Edge *rev;
		Edge(int to, int capacity) : to(to), capacity(capacity) {}
	};
	
	int N;
	int source, sink;
	vector<vector<Edge*>> graph;
	vector<bool> check;
	
	MaximumFlow(int N, int source, int sink) : N(N), source(source), sink(sink) {
		graph.resize(N);
		check.resize(N);
	}
	
	void add_edge(int u, int v, int cap) {
		Edge *ori = new Edge(v, cap);
		Edge *rev = new Edge(u, 0);
		ori->rev = rev;
		rev->rev = ori;
		
		graph[u].push_back(ori);
		graph[v].push_back(rev);
	}
	
	int dfs(int x, int c) {
		if(check[x]) return 0;
		check[x] = true;
		if(x == sink) return c;
		
		for(int i = 0; i < graph[x].size(); i++) {
			if(graph[x][i]->capacity > 0) {
				int nc = graph[x][i]->capacity;
				if(c != 0 && c < nc) nc = c;
				int f = dfs(graph[x][i]->to, nc);
				if(f) {
					graph[x][i]->capacity -= f;
					graph[x][i]->rev->capacity += f;
					return f;
				}
			}	
		}
		
		return 0;
	}
	
	int flow() {
		int ans = 0;
		while(true) {
			fill(check.begin(), check.end(), false);
			int f = dfs(source, 0);
			if(f == 0) break;
			ans += f;
		}
		return ans;
	}
};

int node(const char& x) {
	if(x & (1 << 5)) return x - 'a' + 26;
	return x - 'A';
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
