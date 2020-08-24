/* reference: justicehui */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e3+1;

int N,M,K;
vector<pi> a[MAX];
int d[MAX];

bool go(int f) {
	memset(d,0x3f,sizeof(d));
	
	priority_queue<pi> q;
	q.push({0,1});
	d[1]=0;
	
	while(!q.empty()) {
		int cost=-q.top().first;
		int x=q.top().second;
		q.pop();
		
		if(d[x]<cost) continue;
		for(auto& next : a[x]) {
			int y=next.first;
			int weight=cost+(next.second>f);
			
			if(d[y]>weight) {
				d[y]=weight;
				q.push({-weight,y});
			}
		}
	}
	
	return d[N]<=K;
}

int main() {
	cin>>N>>M>>K;
	
	for(int i=0; i<M; i++) {
		int u,v,c;
		cin>>u>>v>>c;
		
		a[u].push_back({v,c});
		a[v].push_back({u,c});
	}
	
	int ans=-1;
	int L=0, R=1e9;
	while(L<=R) {
		int mid=(L+R)/2;
		
		if(go(mid)) {
			ans=mid;
			R=mid-1;
		} else {
			L=mid+1;
		}
	}
	cout<<ans;
	
	return 0;
}
