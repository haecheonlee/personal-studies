#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
using PI=pair<int,int>;

const long long INF=1e9*5e5;
long long dist[10001][21];
bool check[10001][21];

int main() {
	int n,m,k;
	cin>>n>>m>>k;

	// initialization for dist
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=k; j++) dist[i][j]=INF;
	}
	
	vector<PI> a[n+1];
	for(int i=0; i<m; i++) {
		int from, to, cost;
		cin>>from>>to>>cost;
		
		a[from].push_back(make_pair(to,cost));
		a[to].push_back(make_pair(from, cost));
	}
	
	priority_queue<tuple<int,int,int>> q;
	q.push(make_tuple(0,1,0));
	dist[1][0]=0;
	
	while(!q.empty()) {
		auto p=q.top();
		q.pop();
		
		int from=get<1>(p);
		int step=get<2>(p);
		if(check[from][step]) continue;
		check[from][step]=true;
		
		for(auto next : a[from]) {
			int to=next.first;
			int cost=next.second;
			
			if(step+1<=k && dist[to][step+1]>dist[from][step]) {
				dist[to][step+1]=dist[from][step];
				q.push(make_tuple(-dist[to][step+1], to, step+1));
			}
			
			if(dist[to][step] > dist[from][step] + cost) {
				dist[to][step]=dist[from][step]+cost;
				q.push(make_tuple(-dist[to][step], to, step));
			}
		}
	}
	
	long long ans=INF;
	for(int i=1; i<=k; i++) {
		if(check[n][i] && ans>dist[n][i]) ans=dist[n][i];
	}
	cout<<ans;
	
	return 0;
}
