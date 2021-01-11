/* reference: https://www.cnblogs.com/gzh01/p/9385325.html */

#include <iostream>
#include <vector>
#include <queue>

#define sz(x) (int)(x.size())

using namespace std;

typedef pair<int,int> pii;

const int MAX_N = 1e4 + 1;

int N;
vector<int> G[MAX_N];
int d[MAX_N], p[MAX_N];

int dfs(int u, int x) {
	// from 'x' to 'u'
	p[u] = x;
	if(sz(G[u]) == 1 && u != 1) return d[u] = 1;
	
	int sum = 0;
	for(auto& v : G[u]) {
		if(v == x) continue;
		sum += dfs(v, u);
	}
	
	return d[u] = sum + 1;
}

int main() {
	int N;
	cin >> N;
	
	for(int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1, 0);
	
	vector<int> ans;
	for(int i = 1; i <= N; i++) {
		if(d[1] - d[i] > N / 2) continue;
		
		bool check = true;
		for(auto& v : G[i]) {
			if(v == p[i]) continue;
			if(d[v] > N / 2) {
				check = false; 
				break;
			}
		}
		if(check) ans.push_back(i);
	}

	if(ans.empty()) {
		cout << "NONE" << '\n';
	} else {
		for(auto& x : ans) 
			cout << x << '\n';
	}

	return 0;
}
