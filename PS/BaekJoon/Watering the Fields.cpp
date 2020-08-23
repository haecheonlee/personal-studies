#include <iostream>
#include <queue>

using namespace std;
using pi=pair<int,int>;

int N,C;
pi p[2000];
vector<pi> a[2000];
bool check[2000];

int get_cost(int u, int v) {
	int x=(p[u].first-p[v].first);
	int y=(p[u].second-p[v].second);
	
	return (x*x)+(y*y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N>>C;
	
	for(int i=0; i<N; i++) {
		cin>>p[i].first>>p[i].second;
	}
	
	for(int i=0; i<N; i++) {
		for(int j=i+1; j<N; j++) {
			int cost=get_cost(i,j);
			if(cost>=C) {
				a[i].push_back({j,cost});
				a[j].push_back({i,cost});
			}
		}
	}
	
	priority_queue<pi> q;
	q.push({0,0});
	
	int ans=0;
	while(!q.empty()) {
		int cost=-q.top().first;
		int x=q.top().second;
		q.pop();
		
		if(check[x]) continue;
		check[x]=true;
		ans+=cost;
		
		// adding edges
		for(auto& next : a[x]) {
			int y=next.first;
			int c=next.second;
			
			if(check[y]==false) q.push({-c,y});
		}	
	}
	
	bool is_all_connected=true;
	for(int i=0; i<N; i++) {
		if(check[i]==false) {
			is_all_connected=false;
			break;
		}
	}
	
	if(is_all_connected) cout<<ans;
	else cout<<-1;
	
	return 0;
}
