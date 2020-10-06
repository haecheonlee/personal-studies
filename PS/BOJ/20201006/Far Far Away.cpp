#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N,M;
		cin>>N>>M;
		
		vector<pi> a[N+1];
		for(int i=0; i<N-1; i++) {
			int u,v,c;
			cin>>u>>v>>c;
			
			a[u].push_back({v,c});
		}
		
		int d[N+1];
		memset(d, -1, sizeof(d));
		priority_queue<pi> q;
		q.push({0,1});
		d[1]=0;
		
		while(!q.empty()) {
			int x=q.top().second;
			int cost=q.top().first;
			q.pop();
			
			if(d[x]>cost) continue;
			for(auto& next : a[x]) {
				int y=next.first;
				int next_cost=next.second+cost;
				
				if(d[y]<next_cost) {
					d[y]=next_cost;
					q.push({next_cost, y});
				}
			}
		}
		
		int ans=-1;
		for(int i=1; i<=N; i++) {
			if(d[i]<M) continue;
			ans=max(ans, d[i]);
		}
		cout<<ans<<'\n';
	}

	return 0;
}
