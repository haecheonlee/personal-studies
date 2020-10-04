#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
 
using namespace std;
using pi=pair<int,int>;
 
const int MAX=1e5+10;
const int INF=2e9;
 
vector<pi> a[MAX];
vector<pi> p;
int d[MAX];
 
int main() {
	int N,M;
	cin>>N>>M;
	
	int sx,sy,fx,fy;
	cin>>sx>>sy>>fx>>fy;
	
	p.push_back({sx,sy});
	for(int i=0; i<M; i++) {
		int x,y;
		cin>>x>>y;
	
		p.push_back({x,y});
	}
	p.push_back({fx,fy});
 
	for(int i=0; i<p.size(); i++) {
		for(int j=i+1; j<p.size(); j++) {
			if(j+1==p.size()) {
				int cost=abs(p[i].first-p[j].first)+abs(p[i].second-p[j].second);
 
				a[i].push_back({j, cost});
				a[j].push_back({i, cost});
			} else {
				// instant move
				if(p[i].first==p[j].first || p[i].second==p[j].second) {
					// travel with no cost
					a[i].push_back({j,0});
					a[j].push_back({i,0});
				} else {
					int diff_x=abs(p[i].first-p[j].first);
					int diff_y=abs(p[i].second-p[j].second);
					int dist=abs(p[i].first-p[j].first)+abs(p[i].second-p[j].second);
					int cost=min(diff_x, min(diff_y, dist));
	
					a[i].push_back({j, cost});
					a[j].push_back({i, cost});
				}
			}
		}
	}
 
	fill(d, d+(int)p.size(), INF); 
	priority_queue<pi> q;
	q.push({0,0});
	d[0]=0;
	p.clear();
 
	while(!q.empty()) {
		int cost=-q.top().first;
		int x=q.top().second;
		q.pop();
		
		if(d[x]<cost) continue;
		for(auto& next : a[x]) {
			int y=next.first;
			int next_cost=d[x]+next.second;
			
			if(d[y]>next_cost) {
				d[y]=next_cost;
				q.push({-next_cost, y});
			}
		}
	}
	
	cout<<d[M+1];
	
	return 0;
}

/* failed */
