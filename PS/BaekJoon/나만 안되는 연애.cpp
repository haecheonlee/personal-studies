#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using PI=pair<int,int>;

bool check[1001];
char univ[1001];

int main() {
	int n,m;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++) cin>>univ[i];

	vector<PI> a[n+1];
	for(int i=0; i<m; i++) {
		int from, to, cost;
		cin>>from>>to>>cost;
		
		if(univ[from]==univ[to]) continue;
		
		a[from].push_back(make_pair(to,cost));
		a[to].push_back(make_pair(from,cost));
	}
	
	priority_queue<PI> q;
	for(auto next : a[1]) {
		q.push(make_pair(-next.second, next.first));
	}
	check[1]=true;

	int ans=0;
	while(!q.empty()) {
		int cost=-q.top().first;
		int to=q.top().second;
		q.pop();
		
		if(check[to]) continue;
		check[to]=true;
		ans+=cost;
		
		for(auto next : a[to]) {
			q.push(make_pair(-next.second, next.first));
		}
	}
	
	for(int i=1; i<=n; i++) {
		if(check[i]==false) {
			cout<<-1;
			return 0;
		}
	}
	cout<<ans;

	return 0;
}
