#include <iostream>
#include <vector>

using namespace std;

struct Edge {
	int to;
	int cost;
};

vector<Edge> list[10001];
int d[501];
int inf=100000000;

int main() {
	int n,m;
	cin>>n>>m;
	
	for(int i=0; i<m; i++) {
		int a,b,cost;
		cin>>a>>b>>cost;
		
		list[a].push_back(Edge{b,cost});
	}
	
	for(int i=1; i<=n; i++) d[i]=inf;
	
	d[1]=0;
	bool negative_cycle=false;
	for(int i=1; i<=n; i++) {
		for(int here=1; here<=n; here++) {
			
			if(d[here]==inf) continue;
			for(auto &e : list[here]) {
				int next=e.to;
				int cost=e.cost;
				
				if(d[next]>d[here]+cost) {
					d[next]=d[here]+cost;
					if(i==n) negative_cycle=true;
				}
			}
		}
	}
	
	if(negative_cycle) {
		cout<<-1<<'\n';
	} else {
		for(int i=2; i<=n; i++) {
			if(d[i]==inf) d[i]=-1;
			cout<<d[i]<<'\n';
		}
	}
	
	return 0;
}

/*
INPUT:
3 4
1 2 4
1 3 3
2 3 -1
3 1 -2

OUTPUT:
4
3
*/
