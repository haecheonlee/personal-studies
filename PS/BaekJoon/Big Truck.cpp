#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int INF=1e9;
const int MAX=1e2+1;

int N,M;
vector<pi> a[MAX];
int d[MAX];
int t[MAX], p[MAX];

int main() {
	cin>>N;
	
	// number of itmes from 1 to N
	for(int i=1; i<=N; i++) cin>>t[i];
	
	// adding edges
	cin>>M;
	for(int i=0; i<M; i++) {
		int u,v,c;
		cin>>u>>v>>c;
		
		a[u].push_back({v,c});
		a[v].push_back({u,c});
	}
	
	fill(d,d+MAX,INF);
	priority_queue<tuple<int,int,int>> q;
	q.push({0,t[1],1});
	d[1]=0;
	p[1]=t[1];
	
	while(!q.empty()) {
		int cost,items,x;
		tie(cost,items,x)=q.top();
		cost=-cost;
		q.pop();
		
		if(d[x]<cost) continue;
		for(auto& next : a[x]) {
			int y=next.first;
			int weight=cost+next.second;

			if(d[y]>weight) {
				d[y]=weight;
				p[y]=items+t[y];
				q.push({-weight,p[y],y});
			} else if(d[y]==weight) {
				p[y]=max(p[y],items+t[y]);
				q.push({-weight,p[y],y});
			}
		}
	}
	
	if(d[N]==INF) cout<<"impossible";
	else cout<<d[N]<<' '<<p[N];
	
	return 0;
}
