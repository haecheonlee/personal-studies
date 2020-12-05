#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<string, vector<string>> a;
map<string, bool> m;

void dfs(string s) {
	m[s] = true;
	
	for(auto& x : a[s]) {
		if(m[x] == false) dfs(x);
	}
}

int main() {
	int tc = 1;
	
	while(1) {
		int N;
		cin >> N;
		
		if(N == 0) break;
		
		a.clear();
		m.clear();
		
		for(int i = 0; i < N; i++) {
			string u, v;
			cin >> u >> v;
			
			m[u] = m[v] = false;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		
		int ans = 0;
		for(auto it : a) {
			string s = it.first;
			if(m[s] == false) {
				for(auto& x : it.second) {
					if(m[x] == false) {
						ans++;
						dfs(x);
					}
				}
			}
		}
		
		cout << tc++ << ' ' << ans << '\n';
	}
	
	return 0;
}
