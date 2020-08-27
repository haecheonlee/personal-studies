#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e3+1;

vector<pi> a[MAX];
int d[MAX];

int main() {
	int N,Q;
	cin>>N>>Q;

	for(int i=0; i<N-1; i++) {
		int u,v,c;
		cin>>u>>v>>c;
		
		a[u].push_back({v,c});
		a[v].push_back({u,c});
	}

	while(Q--) {
		int u,v;
		cin>>u>>v;
		
		memset(d,-1,sizeof(d));
		queue<int> q;
		q.push(u);
		d[u]=0;
		
		while(!q.empty()) {
			int x=q.front();
			q.pop();
			
			for(auto& next : a[x]) {
				int y=next.first;
				int cost=next.second;
				
				if(d[y]==-1) {
					d[y]=d[x]+cost;
					q.push(y);
				}
			}
		}
		
		cout<<d[v]<<'\n';
	}

	return 0;
}
