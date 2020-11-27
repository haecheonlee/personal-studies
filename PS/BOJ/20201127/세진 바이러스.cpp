#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX = 1e5 + 1;

vector<int> G[MAX];
int cnt, SN;
int dfsn[MAX], sn[MAX], ind[MAX];
bool finished[MAX];
stack<int> S;
vector<vector<int>> SCC;

int dfs(int u) {
	dfsn[u] = ++cnt;
	S.push(u);
	
	int result = dfsn[u];
	for(auto& v : G[u]) {
		if(dfsn[v] == 0) result = min(result, dfs(v));
		else if(!finished[v]) result = min(result, dfsn[v]);
	}
	
	if(result == dfsn[u]) {
		vector<int> scc;
		while(1) {
			int t = S.top();
			S.pop();
			
			scc.push_back(t);
			finished[t] = true;
			sn[t] = SN;
			if(t == u) break;
		}
		
		SCC.push_back(scc);
		SN++;
	}
	
	return result;
}

int main() {
	int N, M;
	cin >> N >> M;
	
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		
		G[u].push_back(v);
	}
	
	for(int i = 0; i < N; i++) if(dfsn[i] == 0) dfs(i);

	for(int u = 0; u < N; u++) {
		for(auto& v : G[u]) {
			if(sn[u] != sn[v]) ind[sn[v]]++;
		}
	}
	
	int ans = 0;
	for(int i = 0; i < SN; i++) {
		if(ind[i] == 0) ans++;
	}
	cout << ans << '\n';

	return 0;
}
