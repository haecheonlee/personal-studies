#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e3+1;

vector<int> a[MAX];
int adj[MAX][MAX];
int p[MAX];
pi d[MAX];

int main() {
	int N,K;
	cin>>N>>K;
	
	for(int i=0; i<N; i++) cin>>p[i];
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cin>>adj[i][j];
			if(adj[i][j]>0) a[i].push_back(j);
		}
	}
	
	memset(d, 0x3f, sizeof(d));
	priority_queue<tuple<int,int,int>> q;
	q.push({0,0,0});
	d[0].first=d[0].second=0;
	
	while(!q.empty()) {
		int change, dist, x;
		tie(change, dist, x)=q.top();
		change=-change;
		dist=-dist;
		q.pop();
		
		if(d[x].first<change) continue;
		else if(d[x].first==change) if(d[x].second<dist) continue;
		
		for(auto& y : a[x]) {
			int next_change=change + (p[x]!=p[y]);
			int next_dist=dist+adj[x][y];
			
			if(d[y].first>next_change) {
				d[y].first=next_change;
				d[y].second=next_dist;
				q.push({-next_change, -next_dist, y});
			} else if(d[y].first==next_change) {
				if(d[y].second>next_dist) {
					d[y].second=next_dist;
					q.push({-next_change, -next_dist, y});
				}
			}
		}
	}
	
	cout<<d[K].first<<' '<<d[K].second;

	return 0;
}
