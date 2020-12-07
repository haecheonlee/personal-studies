#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<string,vector<string>> m;
map<string,int> grp;

bool dfs(string s, int g) {
	grp[s] = g;
	
	for(auto& ns : m[s]) {
		if(grp[ns] == 0) {
			if(!dfs(ns, 3 - g)) return false;
		} else if(grp[ns] == grp[s]) {
			return false;
		}
	}
	
	return true;
}

int main() {
	int T;
	cin >> T;
	
	for(int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;
		
		m.clear();
		grp.clear();
		
		for(int i = 0; i < N; i++) {
			string a, b;
			cin >> a >> b;
			
			m[a].push_back(b);
			m[b].push_back(a);
			
			grp[a] = grp[b] = 0;
		}
		
		bool ans = true;
		for(auto it : m) {
			string name = it.first;
			if(grp[name] == 0) ans = dfs(name, 1); 
			if(!ans) break;
		}
	
		cout << "Case #" << tc << ": " << (ans ? "Yes" : "No") << '\n';
	}

	return 0;
}
