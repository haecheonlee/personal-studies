#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<string, vector<string>> a;
map<string, int> visited;
set<string> ans;

void dfs(string now) {
	ans.insert(now);
	visited[now]++;
	
	for(auto& next : a[now]) {
		if(visited[next]==0) dfs(next);
	}
}

int main() {
	int N;
	cin>>N;
	
	for(int i=0; i<N; i++) {
		string p,is,q;
		cin>>p>>is>>q;
		
		a[p].push_back(q);
	}
	
	for(auto& x : a["Baba"]) dfs(x);
	for(auto& x : ans) cout<<x<<'\n';
	
	return 0;
}
