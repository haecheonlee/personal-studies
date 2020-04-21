#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using P=pair<int,int>;

const int INF=1e8;

vector<P> list[1000];
int d[1000];
int n,e,v1,v2;

int distance(int start, int end) {
	for(int i=1; i<=n; i++) d[i]=INF;
	
	priority_queue<P> pq;
	pq.push(make_pair(0,start));
	d[start]=0;
	
	while(!pq.empty()) {
		int here=pq.top().second;
		int cost=-pq.top().first;
		pq.pop();
		
		if(d[here]<cost) continue;
		for(auto &next : list[here]) {
			int to=next.first;
			int next_cost=next.second+cost;
			
			if(d[to]>next_cost) {
				d[to]=next_cost;
				pq.push(make_pair(-next_cost,to));
			}
		}
	}
	
	return d[end];
}

int main() {
	cin>>n>>e;
	
	for(int i=0; i<e; i++) {
		int p1,p2,cost;
		cin>>p1>>p2>>cost;
		
		list[p1].push_back(make_pair(p2,cost));
		list[p2].push_back(make_pair(p1,cost));
	}
	
	cin>>v1>>v2;
	
	int path1=distance(1,v1)+distance(v1,v2)+distance(v2,n);
	int path2=distance(1,v2)+distance(v2,v1)+distance(v1,n);
	int ans=min(path1,path2);
	
	if(ans>=INF) cout<<-1;
	else cout<<ans;

	return 0;
}

/*
INPUT:
4 6
1 2 3
2 3 3
3 4 1
1 3 5
2 4 5
1 4 4
2 3

OUTPUT:
7
*/
