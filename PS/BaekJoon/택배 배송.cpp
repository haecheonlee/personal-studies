#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using PI=pair<int,int>;

const int MAX=5e5+1;
const int inf=1e9+1;

vector<PI> a[MAX];
int dist[MAX];

int main() {
	int n,m;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++) dist[i]=inf;
	for(int i=0; i<m; i++) {
		int x,y,z;
		cin>>x>>y>>z;
		
		a[x].push_back(make_pair(z,y));
		a[y].push_back(make_pair(z,x));
	}
	
	priority_queue<PI> q;
	q.push(make_pair(0,1));
	dist[1]=0;
	
	while(!q.empty()) {
		int cost=-q.top().first;
		int from=q.top().second;
		q.pop();
		
		if(dist[from]<cost) continue;
		for(auto next : a[from]) {
			int next_cost=dist[from]+next.first;
			int to=next.second;
			
			if(dist[to]>next_cost) {
				dist[to]=next_cost;
				q.push(make_pair(-dist[to], to));
			}
		}
	}
	
	cout<<dist[n];
	
	return 0;
}
