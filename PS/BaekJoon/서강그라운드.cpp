#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pi=pair<int,int>;

const int inf=5e8;

vector<pi> a[101];
int item[101];

int go(int start, int n, int m) {
	int dist[n+1];
	for(int i=1; i<=n; i++) dist[i]=inf;
	
	priority_queue<pi> q;
	q.push(make_pair(0,start));
	dist[start]=0;
	
	while(!q.empty()) {
		int cost=-q.top().first;
		int from=q.top().second;
		q.pop();
		
		if(dist[from]<cost) continue;
		for(auto next : a[from]) {
			int to=next.first;
			int next_cost=dist[from]+next.second;
			
			if(next_cost<=m) {
				if(dist[to]>next_cost) {
					dist[to]=next_cost;
					q.push(make_pair(-dist[to], to));
				}
			}
		}
	}
	

	int sum=0;
	for(int i=1; i<=n; i++) {
		if(dist[i]>m) continue;
		sum+=item[i];
	}
	
	return sum;
}

int main() {
	int n,m,r;
	cin>>n>>m>>r;
	
	for(int i=1; i<=n; i++) cin>>item[i];
	
	for(int i=0; i<r; i++) {
		int from, to, cost;
		cin>>from>>to>>cost;
		
		a[from].push_back(make_pair(to, cost));
		a[to].push_back(make_pair(from, cost));
	}
	
	int ans=0;
	for(int i=1; i<=n; i++) ans=max(go(i,n,m), ans);
	cout<<ans;
	
	return 0;
}
