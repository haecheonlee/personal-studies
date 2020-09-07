#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e2+1;
const int INF=1e9;

vector<pi> a[MAX];
pi d[MAX];	// first: cost, second: number of visited nodes

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<M; i++) {
		int u,v,c,d,e;
		cin>>u>>v>>c>>d>>e;
		
		int cost=c+(d*max(e-10, 0));
		a[u].push_back({v,cost});
	}

	// dijkstra
	for(int i=1; i<=N; i++) d[i].first=d[i].second=INF;
	
	priority_queue<pi> q;
	q.push({0,1});
	d[1]=make_pair(0,1);
	while(!q.empty()) {
		int x=q.top().second;
		int cost=-q.top().first;
		q.pop();
		
		if(d[x].first<cost) continue;
		for(auto& next : a[x]) {
			int y=next.first;
			int weight=cost+next.second;
			
			if(d[y].first>weight) {
				d[y].first=weight;
				d[y].second=d[x].second+1;
				q.push({-d[y].first, y});
			} else if(d[y].first==weight) {
				d[y].second=min(d[x].second+1, d[y].second);
				q.push({-d[y].first, y});
			}
		}
	}
	
	if(d[N].first==INF) cout<<"It is not a great way.";
	else cout<<d[N].first<<' '<<d[N].second;
	
	return 0;
}
