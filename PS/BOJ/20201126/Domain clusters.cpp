/* reference: blog.naver.com/kks227/220802519976 */
/* algorithm: strongly connected component */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX = 5e3 + 1;

int V, E, cnt, dfsn[MAX];
vector<int> G[MAX];
bool finished[MAX];
stack<int> S;
vector<vector<int>> SCC;

int dfs(int now) {
	dfsn[now] = ++cnt;		// decide on dfsn
	S.push(now);
	
	int result = dfsn[now];	// store the min number in dfsn
	for(int nxt : G[now]) {
		// not visited yet
		if(dfsn[nxt] == 0) result = min(result, dfs(nxt));
		else if(!finished[nxt]) result = min(result, dfsn[nxt]);	// visited but not scc yet
	}
	
	if(result == dfsn[now]) {
		vector<int> nowSCC;
		
		while(1) {
			int t = S.top();
			S.pop();
			
			nowSCC.push_back(t);
			finished[t] = true;
			if(t == now) break;
		}
		
		SCC.push_back(nowSCC);
	}
	
	return result;
}

int main() {
	cin >> V >> E;
	
	for(int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		
		G[u].push_back(v);
	}
	
	for(int i = 1; i <= V; i++) if(dfsn[i] == 0) dfs(i);

	int ans = 0;
	for(auto& g : SCC) ans = max(ans, (int)g.size());
	cout << ans << '\n';
	
	return 0;
}
