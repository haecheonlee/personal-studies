#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pi=pair<int,int>;

const int inf=5e8;

void print(int x, int *p) {
	if(x==-1) return;
	
	print(p[x], p);
	cout<<x<<" ";
}

int main() {
	int t;
	cin>>t;
	
	for(int i=1; i<=t; i++) {
		int n,m;
		cin>>m>>n;
		
		vector<pi> a[n];
		int dist[n];
		int p[n];
		
		for(int i=0; i<n; i++) {
			dist[i]=inf;
			p[i]=-1;
		}
		
		for(int i=0; i<m; i++) {
			int x,y,z;
			cin>>x>>y>>z;
			
			a[x].push_back(make_pair(y,z));
			a[y].push_back(make_pair(x,z));
		}
		
		priority_queue<pi> q;
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
					p[y]=x;
					q.push(make_pair(-dist[y],y));
				}
			}
		}
		
		if(dist[n-1]==inf) {
			printf("Case #%d: -1", i);
		}
		else {
			printf("Case #%d: ", i);
			print(n-1,p);
		}
		cout<<'\n';
	}

	return 0;
}
