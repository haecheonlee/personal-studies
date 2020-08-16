#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

vector<pi> a[1001];
bool in[1001];
int d[1001];

void dfs(int x) {
	for(auto& p : a[x]) {
		int y=p.first;
		int cost=p.second;
		
		if(d[y]<d[x]+cost) {
			d[y]=d[x]+cost;
			dfs(y);
		}
	}
}

int main() {
	int N,M;
	cin>>N>>M;

	for(int i=0; i<M; i++) {
		int u,v,c;
		cin>>u>>v>>c;
		
		a[u].push_back({v,c});
		in[v]=true;
	}
	
	for(int i=1; i<=N; i++) {
		if(in[i]==false) dfs(i);
	}
	
	int ans=0;
	for(int i=1; i<=N; i++) ans=max(ans,d[i]);
	cout<<ans;

	return 0;
}
