#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pii=pair<int,int>;

const int MAX=5e3+1;
const int INF=1e9;

vector<int> A,B;
vector<pii> a[MAX];
int d[MAX];

int main() {
	int N,M,S,K;
	cin>>N>>M>>S>>K;
	
	A.resize(K), B.resize(K);
	for(int i=0; i<K; i++) cin>>A[i];
	for(int i=0; i<K; i++) cin>>B[i];
	
	for(int i=0; i<M; i++) {
		int u,v,c;
		cin>>u>>v>>c;
		
		a[u].push_back({v,c});
		a[v].push_back({u,c});
	}
	
	fill(d, d+N+1, INF);
	priority_queue<pii> q;
	q.push({0,S});
	d[S]=0;
	
	while(!q.empty()) {
		int c=-q.top().first;
		int x=q.top().second;
		q.pop();
		
		for(auto& next : a[x]) {
			int y=next.first;
			int nc=c+next.second;
			
			if(d[y]>nc) {
				d[y]=nc;
				q.push({-nc,y});
			}
		}
	}
	
	int aL=INF, bL=INF;
	for(auto& x : A) aL=min(aL, d[x]);
	for(auto& x : B) bL=min(bL, d[x]);

	if(aL==INF && bL==INF) cout<<-1;
	else {
		if(aL<bL) cout<<"A\n"<<aL;
		else if(aL>bL) cout<<"B\n"<<bL;
		else cout<<"A\n"<<aL;
	}

	return 0;
}
