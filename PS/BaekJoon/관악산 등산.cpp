#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=5e3+1;

int d[MAX], height[MAX];
bool check[MAX];
vector<int> edge[MAX];
vector<pi> a;

void dfs(int x, int parent, int count) {
	for(auto& y : edge[x]) {
		if(height[y]<height[x]) {
			if(y!=parent) {
				if(d[y]==-1 || d[y]<count+1) {
					d[y]=max(d[y], count+1);
					dfs(y, x, count+1);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin>>N>>M;
	
	for(int i=1; i<=N; i++) {
		cin>>height[i];
		a.push_back({height[i],i});
	}
	sort(a.rbegin(), a.rend());	// sort by height of each node
	
	for(int i=0; i<M; i++) {
		int u,v;
		cin>>u>>v;
		
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	
	memset(d, -1, sizeof(d));
	for(auto& p : a) {
		if(d[p.second]==-1) {
			d[p.second]=1;
			dfs(p.second, -1, 1);
		}
	}
	for(int i=1; i<=N; i++) cout<<d[i]<<'\n';

	return 0;
}
