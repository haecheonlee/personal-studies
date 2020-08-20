#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pi=pair<int,int>;

vector<pi> a[10001];
bool check[10001];

int main() {
	int N,M,T;
	cin>>N>>M>>T;
	
	for(int i=0; i<M; i++) {
		int u,v,cost;
		cin>>u>>v>>cost;
		
		a[u].push_back({v,cost});
		a[v].push_back({u,cost});
	}

	priority_queue<pi> q;
	q.push({0,1});
	
	int ans=0;
	int extra=0;
	while(!q.empty()) {
		int cost=-q.top().first;
		int x=q.top().second;
		q.pop();
		
		if(check[x]) continue;
		check[x]=true;
		if(x!=1) ans+=(cost+((extra++)*T));
		for(auto& p : a[x]) {
			int y=p.first;
			int weight=p.second;
			
			if(check[y]==false) q.push({-weight,y});
		}
	}
	cout<<ans;

	return 0;
}
