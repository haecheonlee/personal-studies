/* https://ioqoo.tistory.com/45 */

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
using pi=pair<int,int>;
const int INF=1e9;

int N,M;
int A,B,K,G;

vector<pi> a[1001];
vector<int> b;
int d[1001];	// 상근이 시간
int adj[1001][1001];
pi forbid[1001][1001];

int main() {
	cin>>N>>M;
	cin>>A>>B>>K>>G;

	b.resize(G);
	for(int i=0; i<G; i++) cin>>b[i];

	for(int i=0; i<M; i++) {
		int U,V,L;
		cin>>U>>V>>L;
		
		a[U].push_back({V,L});
		a[V].push_back({U,L});
		
		adj[U][V]=adj[V][U]=L;
	}

	// 고돌라 거리 시간 계산
	int distance=0;
	for(int i=0; i<G-1; i++) {
		forbid[b[i]][b[i+1]]=forbid[b[i+1]][b[i]]={distance, distance+adj[b[i]][b[i+1]]};
		distance+=adj[b[i]][b[i+1]];
	}

	// 상근이 배달 시작
	// initialization
	fill(d+1, d+N+1, INF);

	priority_queue<pi> q;
	q.push({-K,A});	// distance, vertex
	d[A]=K;
	while(!q.empty()) {
		int curr_dist=-q.top().first;
		int here=q.top().second;
		q.pop();
		
		if(d[here]<curr_dist) continue;
		for(auto &p : a[here]) {
			int there=p.first;
			int weight=p.second;
			
      // 풀기 어려웠던 부분
			auto F=forbid[here][there];
			if(F.first<=curr_dist && curr_dist<=F.second) {
				weight+=(F.second-curr_dist);
			}
			
			if(d[there]>curr_dist+weight) {
				d[there]=curr_dist+weight;
				q.push({-d[there], there});
			}
		}
	}

	cout<<d[B]-K;

	return 0;
}
