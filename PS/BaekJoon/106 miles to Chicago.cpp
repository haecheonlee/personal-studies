#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;
using pi=pair<double,int>;

int N,M;
vector<pi> a[101];
double d[101];

double dijkstra() {
	priority_queue<pi> q;
	q.push({1,1});
	d[1]=1;

	while(!q.empty()) {
		double cost=q.top().first;
		int x=q.top().second;
		q.pop();
		
		if(d[x]>cost) continue;
		for(auto& p : a[x]) {
			int y=p.second;
			double weight=p.first*cost;

			if(y==1) continue;
			if(d[y]<weight) {
				d[y]=weight;
				q.push({weight,y});
			}
		}
	}
	
	return d[N]*100;
}

int main() {
	while(cin>>N) {
		if(N==0) break;
	
		// reset
		for(int i=1; i<=N; i++) {
			a[i].clear();
			d[i]=0;
		}
		
		cin>>M;
		for(int i=0; i<M; i++) {
			int u,v;
			double cost;
			cin>>u>>v>>cost;
			
			cost/=100;
			a[u].push_back({cost,v});
			a[v].push_back({cost,u});
		}
		
		cout<<setprecision(6)<<fixed<<dijkstra()<<'\n';
	}

	return 0;
}
