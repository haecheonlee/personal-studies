/* reference: kks227's blog */

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

const int MAX = 1e5 + 1;

vector<int> G[MAX];
int cnt, SN;
int dfsn[MAX], sn[MAX];
stack<int> S;
bool finished[MAX];
vector<vector<int>> SCC;

int dfs(int now) {
	dfsn[now] = ++cnt;
	S.push(now);
	
	int result = dfsn[now];
	for(int nxt : G[now]) {
		if(dfsn[nxt] == 0) result = min(result, dfs(nxt));
		else if(!finished[nxt]) result = min(result ,dfsn[nxt]);
	}
	
	if(result == dfsn[now]) {
		vector<int> scc;
		
		while(1) {
			int t = S.top();
			S.pop();
			
			scc.push_back(t);
			finished[t] = true;
			sn[t] = SN;
			if(t == now) break;
		}
		
		SCC.push_back(scc);
		SN++;
	}
	
	return result;
}

int main() {
	int T;
	cin >> T;
	
	while(T--) {
		int N, M;
		cin >> N >> M;

		// reset		
		for(int i = 1; i <= N; i++) G[i].clear();
		SCC.clear();
		memset(dfsn, 0, sizeof(dfsn));
		memset(sn, 0, sizeof(sn));
		memset(finished, false, sizeof(finished));
		cnt = SN = 0;
		
		for(int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;
			
			G[u].push_back(v);
		}
		
		for(int i = 1; i <= N; i++) if(dfsn[i] == 0) dfs(i);
		
		// count indegree
		int ind[MAX] = {0};
		for(int i = 1; i <= N; i++) {
			for(int j : G[i]) if(sn[i] != sn[j]) ind[sn[j]]++;
		}
		
		int ans = 0;
		for(int i = 0; i < SN; i++) {
			if(ind[i] == 0) ans++;
		}
		cout << ans << '\n';
	}

	return 0;
}
