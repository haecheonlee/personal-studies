#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using pi=pair<int,int>;

vector<pi> a[1001];
bool check[1001];

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<M; i++) {
		int u,v,c;
		cin>>u>>v>>c;
		
		a[u].push_back({v,c});
		a[v].push_back({u,c});
	}

	priority_queue<pi> q;
	check[1]=true;
	for(auto& y : a[1]) {
		q.push({y.second, y.first});	// cost, edge
	}

	int ans=0;
	while(!q.empty()) {
		int cost=q.top().first;
		int x=q.top().second;
		q.pop();
		
		if(check[x]) continue;
		check[x]=true;
		ans+=cost;
		for(auto& y : a[x]) {
			if(check[y.first]==false) q.push({y.second, y.first});
		}
	}
	
	bool isAllConnected=true;
	for(int i=1; i<=N; i++) {
		if(check[i]==false) {
			isAllConnected=false;
			break;	
		}
	}
	
	if(isAllConnected) cout<<ans;
	else cout<<-1;

	return 0;
}
