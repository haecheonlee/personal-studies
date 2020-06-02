#include <iostream>
#include <vector>

using namespace std;

struct Edge {
	int from, to, cost;
};

const int INF=1e9;
int d[501];

int main() {
	int t;
	cin>>t;
	
	while(t--) {
		int n,m,w;
		cin>>n>>m>>w;
		
		vector<Edge> a(2*m+w);
		for(int i=0; i<m; i++) {
			cin>>a[i].from>>a[i].to>>a[i].cost;
			a[i+m]=a[i];
			
			swap(a[i+m].from, a[i+m].to);
		}
		
		for(int i=2*m; i<2*m+w; i++) {
			cin>>a[i].from>>a[i].to>>a[i].cost;
			a[i].cost*=-1;
		}
		
		m=2*m+w;
		bool ok=false;
		
		for(int i=1; i<=n; i++) {
			for(int j=0; j<m; j++) {
				int x=a[j].from;
				int y=a[j].to;
				int z=a[j].cost;
				
				if(d[x]!=INF && d[y]>d[x]+z) {
					d[y]=d[x]+z;
					if(i==n) ok=true;
				}
			}
		}
		
		if(ok) cout<<"YES\n";
		else cout<<"NO\n";
	}

	return 0;
}
