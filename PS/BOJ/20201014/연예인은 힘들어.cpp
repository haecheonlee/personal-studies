#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e2+5;
const int INF=1e8;

vector<pi> a[MAX];
int d1[MAX], d2[MAX];

void dijkstra(int sx, int *d) {
	fill(d, d+MAX, INF);
	
	priority_queue<pi> q;
	q.push({0,sx});
	d[sx]=0;
	
	while(!q.empty()) {
		int c=-q.top().first;
		int x=q.top().second;
		q.pop();
		
		if(d[x]<c) continue;
		for(auto& next : a[x]) {
			int y=next.first;
			int nc=next.second+c;
			
			if(d[y]>nc) {
				d[y]=nc;
				q.push({-nc,y});
			}
		}
	}
}

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<M; i++) {
		int u,v,c;
		cin>>u>>v>>c;
		
		a[u].push_back({v,c});
		a[v].push_back({u,c});
	}
	
	int A,B;
	cin>>A>>B;
	
	dijkstra(A, d1);
	dijkstra(B, d2);

	int least=INF;
	for(int i=1; i<=N; i++) {
		if(d1[i]==INF || d2[i]==INF || A==i || B==i) continue;
		least=min(least, d1[i] + d2[i]);
	}

	int ans=-1, taken=INF;
	if(least!=INF) {
		for(int i=1; i<=N; i++) {
			if(A==i || B==i) continue;
			
			if(d1[i]+d2[i]==least) {
				if(d1[i]<=d2[i]) {
					if(d1[i]<taken) {
						ans=i;
						taken=d1[i];
					}
				}
			}
		}
	}
	cout<<ans;
	
	return 0;
}
