#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pi=pair<int,int>;

const int inf=5e8;

vector<pi> a[1001];

vector<int> dijkstra(int start, int n) {
	vector<int> dist(n+1);
	bool check[n+1];
	for(int i=1; i<=n; i++) {
		dist[i]=inf;
		check[i]=false;	
	}
	
	priority_queue<pi> q;
	q.push(make_pair(0,start));
	dist[start]=0;
	
	while(!q.empty()) {
		int cost=-q.top().first;
		int from=q.top().second;
		q.pop();
		
		if(check[from]) continue;
		check[from]=true;
		for(auto next : a[from]) {
			int to=next.first;
			int c=next.second;
			
			if(dist[to]>dist[from]+c) {
				dist[to]=dist[from]+c;
				q.push(make_pair(-dist[to], to));
			}
		}
	}
	
	return dist;
}

int main() {
	int t;
	cin>>t;
	
	while(t--) {
		int n,m;
		cin>>n>>m;
		
		for(int i=1; i<=1001; i++) a[i].clear();
		
		for(int i=0; i<m; i++) {
			int from,to,cost;
			cin>>from>>to>>cost;
			
			a[from].push_back(make_pair(to, cost));
			a[to].push_back(make_pair(from, cost));
		}

		int k;
		cin>>k;
		
		vector<vector<int>> list(k);
		for(int i=0; i<k; i++) {
			int x;
			cin>>x;
			
			list[i]=dijkstra(x,n);
		}

		int room=-1, cost=-1;
		for(int i=1; i<=n; i++) {
			int sum=0;
			
			for(int j=0; j<k; j++) sum+=list[j][i];
			
			if(room==-1 || cost>sum) {
				room=i;
				cost=sum;
			}
		}
		
		cout<<room<<'\n';
	}

	return 0;
}
