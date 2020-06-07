#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using PI=pair<long long,long long>;

const int MAX=1e5+1;
const long long inf=1e12;

long long dist[MAX];
bool check[MAX];
vector<PI> a[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=0; i<n; i++) {
		cin>>check[i];
		dist[i]=inf;	
	}
	
	// position of nexus is always true
	check[n-1]=false;
	
	for(int i=0; i<m; i++) {
		int from, to, cost;
		cin>>from>>to>>cost;
		
		if(check[from] || check[to]) continue;
		a[from].push_back(make_pair(to, cost));
		a[to].push_back(make_pair(from, cost));
	}
	
	priority_queue<PI> q;
	q.push(make_pair(0,0));
	dist[0]=0;

	while(!q.empty()) {
		int x=q.top().second;
		int z=-q.top().first;
		q.pop();
		
		if(dist[x]<z) continue;
		for(auto next : a[x]) {
			int y=next.first;
			int cost=next.second;
			
			if(dist[y]>dist[x]+cost) {
				dist[y]=dist[x]+cost;
				q.push(make_pair(-dist[y], y));
			}
		}
	}
	
	if(dist[n-1]==inf) cout<<-1;
	else cout<<dist[n-1];
	
	return 0;
}
