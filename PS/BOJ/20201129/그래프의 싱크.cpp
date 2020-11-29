/* reference: kks227 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 5e3 + 1;

vector<int> G[MAX];
int N, M, cnt, SN;
int dfsn[MAX], sn[MAX], outd[MAX];
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
		
		SN++;
		SCC.push_back(scc);
	}
	
	return result;
}


int main() {
	while(1) {
		// reset
		for(int i = 0; i < MAX; i++) G[i].clear();
		cnt = SN = 0;
		memset(dfsn, 0 ,sizeof(dfsn));
		memset(sn, 0, sizeof(sn));
		memset(outd, 0, sizeof(outd));
		memset(finished, false, sizeof(finished));
		
		cin >> N;
		if(N == 0) break;
		cin >> M;
		
		for(int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;
			
			G[u].push_back(v);
		}
		
		for(int i = 1; i <= N; i++) if(dfsn[i] == 0) dfs(i);
		for(int i = 1; i <= N; i++) {
			for(auto& v : G[i]) {
				if(sn[i] != sn[v]) outd[sn[i]]++;
			}
		}
		
		vector<int> ans;
		for(int i = 1; i <= N; i++) if(outd[sn[i]] == 0) ans.push_back(i);
		sort(ans.begin(), ans.end());
		
		for(auto& x : ans) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}
