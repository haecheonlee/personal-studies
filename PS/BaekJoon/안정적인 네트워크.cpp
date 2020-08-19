#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pi=pair<int,int>;

vector<pair<int,pi>> a;
int p[1001];

int Find(int x) {
	if(p[x]==x) return x;
	return p[x]=Find(p[x]);
}

void Union(int x, int y) {
	x=Find(x);
	y=Find(y);
	
	p[x]=y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<M; i++) {
		int u,v;
		cin>>u>>v;
		a.push_back({0,{u,v}});
	}
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			int cost;
			cin>>cost;
			if(i!=j) a.push_back({cost, {i,j}});
		}
	}
	
	for(int i=1; i<=N; i++) p[i]=i;
	sort(a.begin(), a.end());
	
	int ans=0;
	vector<pi> selected;
	for(auto& p : a) {
		int cost=p.first;
		int u=p.second.first;
		int v=p.second.second;
		
		if(u==1 || v==1) continue;
		if(Find(u) != Find(v)) {
			Union(u,v);
			if(cost>0) {
				selected.push_back({u,v});
				ans+=cost;
			}
		}
	}
	cout<<ans<<' '<<selected.size()<<'\n';
	for(auto& edge : selected) cout<<edge.first<<' '<<edge.second<<'\n';

	return 0;
}
