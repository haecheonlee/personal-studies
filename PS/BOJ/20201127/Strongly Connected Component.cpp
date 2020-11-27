#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX = 1e4 + 1;

int N, M;

vector<int> G[MAX];
int cnt, SN;
int dfsn[MAX], sn[MAX];
bool finished[MAX];
stack<int> S;
vector<vector<int>> scc;

int dfs(int u) {
	dfsn[u] = ++cnt;
	S.push(u);
	
	int result = dfsn[u];
	for(auto& v : G[u]) {
		if(dfsn[v] == 0) result = min(result, dfs(v));
		else if(!finished[v]) result = min(result, dfsn[v]);
	}
	
	if(result == dfsn[u]) {
		vector<int> g;
		
		while(1) {
			int t = S.top();
			S.pop();
			
			g.push_back(t);
			finished[t] = true;
			sn[t] = SN;
			if(t == u) break;
		}
		
		sort(g.begin(), g.end());
		scc.push_back(g);
		SN++;
	}
	
	return result;
}

int main() {
	cin >> N >> M;
	
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		
		G[u].push_back(v);
	}
	
	for(int i = 1; i <= N; i++) if(dfsn[i] == 0) dfs(i);	
	sort(scc.begin(), scc.end());
	
	cout << (int)scc.size() << '\n';
	for(auto& g : scc) {
		for(auto& u : g) cout << u << ' ';
		cout << -1 << '\n';
	}
	
	return 0;
}
