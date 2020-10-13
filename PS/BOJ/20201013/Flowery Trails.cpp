/* reference: https://github.com/mpfeifer1/Kattis/blob/master/flowerytrails.cpp */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e4+1;
const int INF=1e9;

vector<pi> a[MAX];
vector<pi> p[MAX];
int d[MAX];
bool check[MAX];

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<M; i++) {
		int u,v,cost;
		cin>>u>>v>>cost;
		
		a[u].push_back({v,cost});
		a[v].push_back({u,cost});
	}
	
	fill(d, d+MAX, INF);
	priority_queue<pi> q;
	q.push({0,0});
	d[0]=0;
	
	while(!q.empty()) {
		int c=-q.top().first;
		int x=q.top().second;
		q.pop();
		
		if(d[x]<c) continue;
		for(auto& next : a[x]) {
			int y=next.first;
			int nc=d[x]+next.second;
			
			if(nc<d[y]) {
				d[y]=nc;
				p[y].clear();
				p[y].push_back({x, next.second});
				q.push({-d[y], y});
			} else if(nc==d[y]) {
				p[y].push_back({x, next.second});
			}
		}
	}
	
	int ans=0;
	queue<int> q2;
	q2.push(N-1);
	check[N-1]=true;
	
	while(!q2.empty()) {
		int x=q2.front();
		q2.pop();
		
		for(auto& next : p[x]) {
			int y=next.first;
			int c=next.second;
			ans+=c;	
			
			if(check[y]==false) {
				check[y]=true;
				q2.push(y);
			}
		}
	}
	
	cout<<ans*2;
	
	return 0;
}
