#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX=1e2+1;

vector<int> a[MAX];
double adj[MAX][MAX];
double d[MAX];
int p[MAX];

int main() {
	int T;
	scanf("%d", &T);
	
	for(int t=1; t<=T; t++) {
		int N,X,Y;
		scanf("%d %d %d", &N, &X, &Y);

		// reset
		memset(adj, 0, sizeof(adj));
		for(int i=1; i<=N; i++) {
			a[i].clear();
			d[i]=-1;
		}

		int M;
		cin>>M;
		
		while(M--) {
			int u,v;
			double cost;
			scanf("%d %d %lf", &u, &v, &cost);

			a[u].push_back(v);
			if(adj[u][v]<cost) adj[u][v]=cost;
		}
		
		priority_queue<pair<double,int>> q;
		q.push({1,X});
		d[X]=1;
		while(!q.empty()) {
			int x=q.top().second;
			double cost=q.top().first;
			q.pop();
			
			if(d[x]>cost) continue;
			for(auto& y : a[x]) {
				double next_weight=adj[x][y]*cost;
				
				if(d[y]<next_weight) {
					d[y]=next_weight;
					q.push({next_weight, y});
				}
			}
		}
		
		printf("Case %d: %g\n", t, d[Y]);
	}

	return 0;
}
