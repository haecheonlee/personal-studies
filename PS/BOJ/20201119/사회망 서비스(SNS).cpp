/* reference: https://justicehui.github.io/koi/2019/04/11/BOJ2533/ */

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int,bool> pib;

const int MAX = 1e6 + 1;

vector<int> a[MAX];
vector<int> g[MAX];
int d[MAX][2];

void dfs(int x, int px) {
	for(auto& y : a[x]) {
		if(y ^ px) {
			g[x].push_back(y);
			dfs(y, x);
		}
	}
}

int go(int x, int flag) {
	int& ret = d[x][flag];
	if(ret != -1) return ret;
	ret = 0;
	
	if(!flag) {
		for(auto& y : g[x]) ret += go(y, 1);
	} else {
		ret += 1;
		
		for(auto& y : g[x]) {
			int t0 = go(y, 0);
			int t1 = go(y, 1);
			
			ret += min(t0, t1);
		}
	}
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	for(int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	dfs(1, 0);
	
	memset(d, -1, sizeof(d));
	cout << min(go(1, 0), go(1, 1));
	
	return 0;
}
