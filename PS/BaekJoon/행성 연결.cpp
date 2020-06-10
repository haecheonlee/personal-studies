#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using PI=pair<long long,int>;

long long a[1001][1001];
bool check[1001];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
		}
	}
	
	priority_queue<PI> q;
	for(int i=2; i<=n; i++) q.push(make_pair(-a[1][i], i));
	check[1]=true;
	
	long long ans=0;
	while(!q.empty()) {
		long long cost=-q.top().first;
		int to=q.top().second;
		q.pop();
		
		if(check[to]) continue;
		check[to]=true;
		ans+=cost;
		for(int i=1; i<=n; i++) {
			if(check[i] || to==i) continue;
			q.push(make_pair(-a[to][i], i));
		}
	}
	cout<<ans;

	return 0;
}
