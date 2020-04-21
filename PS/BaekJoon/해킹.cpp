#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using PI=pair<int,int>;

const int INF=1e9;
int t,n,d,c;

int main() {
	cin>>t;
	
	while(t--) {
		cin>>n>>d>>c;
		
		vector<PI> list[n+1];
		int dist[n+1];
		
		for(int i=1; i<=n; i++) dist[i]=INF;
		for(int i=0; i<d; i++) {
			int a,b,s;
			cin>>a>>b>>s;
			
			list[b].push_back(make_pair(a,s));
		}
		
		priority_queue<PI> pq;
		pq.push(make_pair(0,c));
		dist[c]=0;
		
		while(!pq.empty()) {
			int here=pq.top().second;
			int cost=-pq.top().first;
			pq.pop();
			
			if(dist[here]<cost) continue;
			for(auto &next : list[here]) {
				int to=next.first;
				int next_cost=next.second+cost;
				
				if(dist[to]>next_cost) {
					dist[to]=next_cost;
					pq.push(make_pair(-next_cost,to));
				}
			}
		}
		
		int cnt=0,mx=0;
		for(int i=1; i<=n; i++) {
			if(dist[i]!=INF) {
				cnt++;
				mx=max(dist[i],mx);
			}
		}
		cout<<cnt<<" "<<mx<<'\n';
	}
	
	return 0;
}

/*
INPUT:
2
3 2 2
2 1 5
3 2 5
3 3 1
2 1 2
3 1 8
3 2 4

OUTPUT:
2 5
3 6
*/
