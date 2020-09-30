/* reference: https://www.acmicpc.net/board/view/35350 */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=4e3+1;
const int INF=2e9;

vector<pi> a[MAX];
int d1[MAX], d2[MAX], d3[MAX];

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<M; i++) {
		int u,v,k;
		cin>>u>>v>>k;
		
		a[u].push_back({v,k*2});
		a[v].push_back({u,k*2});
	}
	
	priority_queue<pi> q;

	// moonlight fox
	fill(d1, d1+MAX, INF);
	q.push({0,1});
	d1[1]=0;
	
	while(!q.empty()) {
		int cost=-q.top().first;
		int x=q.top().second;
		q.pop();
		
		if(d1[x]<cost) continue;
		for(auto& next : a[x]) {
			int y=next.first;
			int next_cost=d1[x]+next.second;
			
			if(d1[y]>next_cost) {
				d1[y]=next_cost;
				q.push({-d1[y], y});
			}
		}
	}
	
	// moonlight wolf
	fill(d2, d2+MAX, INF);
	fill(d3, d3+MAX, INF);
	
	priority_queue<pair<int,pair<int,bool>>> q2;
	q2.push({0,{1,true}});
	d3[1]=0;
	
	while(!q2.empty()) {
		int cost=-q2.top().first;
		int x=q2.top().second.first;
		bool fast=q2.top().second.second;
		q2.pop();
		
		if(fast) {
			if(d3[x]<cost) continue;
		} else {
			if(d2[x]<cost) continue;
		}
		
		for(auto& next : a[x]) {
			if(fast) {
				int y=next.first;
				int next_cost=d3[x]+(next.second/2);
				
				if(d2[y]>next_cost) {
					d2[y]=next_cost;
					q2.push({-d2[y], {y, false}});
				}
			} else {
				int y=next.first;
				int next_cost=d2[x]+(next.second*2);
				
				if(d3[y]>next_cost) {
					d3[y]=next_cost;
					q2.push({-d3[y], {y, true}});
				}
			}
		}
	}
	
	int ans=0;
	for(int i=2; i<=N; i++) {
		if(d1[i] < min(d2[i], d3[i])) ans++;
	}
	cout<<ans;

	return 0;
}
