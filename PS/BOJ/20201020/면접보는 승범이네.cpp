#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using ll=long long;
using plli=pair<ll,int>;

const int MAX=1e5+1;
const ll INF=1e12;

vector<plli> a[MAX];
ll d[MAX];
bool check[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M,K;
	cin>>N>>M>>K;
	
	for(int i=0; i<M; i++) {
		int u,v,c;
		cin>>u>>v>>c;
		
		a[v].push_back({1LL*c,u});
	}
	
	fill(d, d+N+1, INF);
	priority_queue<plli> q;
	for(int i=0; i<K; i++) {
		int x;
		cin>>x;
		
		q.push({0,x});
		d[x]=0;
		check[x]=true;
	}
	
	while(!q.empty()) {
		ll c=-q.top().first;
		int x=q.top().second;
		q.pop();
		
		if(d[x]<c) continue;
		for(auto& next : a[x]) {
			ll nc=c+next.first;
			int y=next.second;
			
			if(d[y]>nc) {
				d[y]=nc;
				q.push({-nc,y});
			}
		}
	}
	
	plli ans {0,-1};
	for(int i=1; i<=N; i++) {
		if(check[i]) continue;
		if(d[i]>ans.first) ans.second=i, ans.first=d[i];
	}
	cout<<ans.second<<'\n'<<ans.first;

	return 0;
}
