#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using plli=pair<ll,int>;

const int MAX=1e5+1;
const ll INF=1e12;

vector<int> zombie;
vector<int> a[MAX];
ll d[MAX];
bool check[MAX];
bool danger[MAX];

int main() {
	int N,M,K,S;
	cin>>N>>M>>K>>S;
	
	int P,Q;
	cin>>P>>Q;
	
	zombie.resize(K);
	for(int i=0; i<K; i++) { cin>>zombie[i]; check[zombie[i]]=true; }
	for(int i=0; i<M; i++) { int u,v; cin>>u>>v; a[u].push_back(v), a[v].push_back(u); }

	// get all possible zombies 
	fill(d, d+N+1, INF);
	priority_queue<pii> q1;
	for(auto& x : zombie) { d[x]=0, q1.push({0,x}); }
	
	while(!q1.empty()) {
		int dist=-q1.top().first;
		int x=q1.top().second;
		q1.pop();
		
		if(d[x]<dist) continue;
		for(auto& y : a[x]) {
			int nd=dist+1;
			if(d[y]>nd && nd<=S) { 
				if(check[y]==false) danger[y]=true;
				d[y]=nd;
				q1.push({-nd,y});
			}
		}
	}
	
	// starts travelling
	fill(d, d+MAX, INF);
	priority_queue<plli> q;
	q.push({0,1});
	d[1]=0;
	
	while(!q.empty()) {
		ll c=-q.top().first;
		int x=q.top().second;
		q.pop();
		
		if(d[x]<c) continue;
		for(auto& y: a[x]) {
			// cannot stay in a city where zombie stays
			if(check[y]) continue;
			ll nc=(danger[y] ? Q : P) + c;
			if(y==N) nc=c;
			
			if(d[y]>nc) {
				d[y]=nc;
				q.push({-nc,y});
			}
		}
	}
	
	cout<<d[N];

	return 0;
}
