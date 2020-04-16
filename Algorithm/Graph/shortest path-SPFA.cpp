/* shortest path using SPFA */
/* boj.kr/11657 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF=1e9;

struct Edge {
	int to;
	int cost;
	Edge(int to, int cost) : to(to), cost(cost) {}
};

vector<Edge> list[501];
int d[501];
int cnt[501];
bool visited[501];

int n,m,x,y,z;

int main() {
	cin>>n>>m;
	
	for(int i=0; i<m; i++) {
		cin>>x>>y>>z;
		list[x].push_back(Edge(y,z));
	}

	// initialization
	for(int i=1; i<=n; i++) d[i]=INF;

	queue<int> q;
	q.push(1);
	d[1]=0;
	
	while(!q.empty()) {
		int from=q.front();
		q.pop();
		visited[from]=false;
		
		for(auto &e : list[from]) {
			int to=e.to;
			int cost=e.cost;
			
			if(d[to]>d[from]+cost) {
				d[to]=d[from]+cost;
				if(visited[to]==false) {
					q.push(to);
					
					visited[to]=true;
					cnt[to]+=1;
					
					if(cnt[to]>=n) {
						cout<<-1<<'\n';
						return 0;
					}
				}
			}
		}	
	}

	for(int i=2; i<=n; i++) {
		if(d[i]==INF) cout<<-1<<'\n';
		else cout<<d[i]<<'\n';
	}

	return 0;
}
