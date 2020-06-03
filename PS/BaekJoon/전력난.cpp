#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p[200001];

struct Edge {
	int from, to, cost;
	bool operator<(const Edge &other) const {
		return cost<other.cost;
	}
};

int Find(int x) {
	if(x==p[x]) return x;
	return p[x]=Find(p[x]);
}

void Union(int x, int y) {
	x=Find(x);
	y=Find(y);
	
	p[x]=y;
}

int main() {
	while(1) {
		int n,m;
		cin>>n>>m;
		
		if(n==0 && m==0) break;
		
		for(int i=0; i<n; i++) p[i]=i;
		
		int total=0;
		vector<Edge> a(m);
		for(int i=0; i<m; i++) {
			cin>>a[i].from>>a[i].to>>a[i].cost;
			
			total+=a[i].cost;
		}
		sort(a.begin(), a.end());
		
		int mn=0;	// sum of mst
		for(int i=0; i<m; i++) {
			int x=Find(a[i].from);
			int y=Find(a[i].to);
			
			if(x!=y) {
				Union(x,y);
				mn+=a[i].cost;
			}
		}
		
		cout<<total-mn<<'\n';
	}

	return 0;
}
