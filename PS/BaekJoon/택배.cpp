#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pi=pair<int,int>;

const int inf=5e8;

vector<pi> a[201];
int p[201];
int dist[201];

int main() {
	int n,m;
	cin>>n>>m;
	
	for(int i=0; i<m; i++) {
		int x,y,z;
		cin>>x>>y>>z;
		
		a[x].push_back(make_pair(y,z));
		a[y].push_back(make_pair(x,z));
	}

	priority_queue<pi> q;
	for(int i=1; i<=n; i++) {
		// initialization
		for(int x=1; x<=n; x++) dist[x]=inf;
		
		q.push(make_pair(0,i));
		dist[i]=0;
		
		while(!q.empty()) {
			int cost=-q.top().first;
			int from=q.top().second;
			q.pop();
			
			if(dist[from]<cost) continue;
			for(auto next : a[from]) {
				int to=next.first;
				int c=next.second;
				
				if(dist[to]>dist[from]+c) {
					dist[to]=dist[from]+c;
					p[to]=from;
					q.push(make_pair(-dist[to], to));
				}
			}
		}
		
		for(int x=1; x<=n; x++) {
			if(x==i) {
				cout<<"-";
			}
			else if(p[x]==i) {
				cout<<x;
			}
			else {
				int start=x;
				while(1) {
					if(p[start]==i) {
						cout<<start;
						break;
					} else {
						start=p[start];
					}
				}
			}
			cout<<" ";
		}
		cout<<'\n';
	}

	return 0;
}
