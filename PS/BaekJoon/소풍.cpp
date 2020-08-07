#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int K,N,F;
vector<int> edge[901];
bool is_friend[901][901];
bool check[901];
vector<int> ans;

void dfs(int node, vector<int>& list) {
	if(ans.size()==K) return;
	if(list.size()==K) {
		ans=list;
		return;
	}
	
	for(auto& next : edge[node]) {
		if(check[next]) continue;

		bool is_possible=true;
		for(auto& each : list) {
			if(is_friend[next][each]==false) {
				is_possible=false;
				break;
			}
		}
		
		if(is_possible) {
			if(edge[next].size()>=K-1) {
				check[next]=true;
				list.push_back(next);
				dfs(next, list);
				check[next]=false;
				list.pop_back();
			}
		}
	}
}

int main() {
	cin>>K>>N>>F;
	
	for(int i=0; i<F; i++) {
		int u,v;
		cin>>u>>v;
		
		edge[u].push_back(v);
		edge[v].push_back(u);
		is_friend[u][v]=is_friend[v][u]=true;
	}
	
	for(int i=1; i<=N; i++) sort(edge[i].begin(), edge[i].end());
	for(int i=1; i<=N; i++) {
		if(edge[i].size()>=K-1) {
			memset(check,false,sizeof(check));
			check[i]=true;
			vector<int> list(1,i);
			dfs(i,list);
		}
		
		if(ans.size()==K) {
			for(auto& x : ans) cout<<x<<" ";	
			return 0;
		}
	}
	
	cout<<-1;
	
	return 0;
}
