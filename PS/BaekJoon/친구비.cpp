#include <iostream>

using namespace std;

int parent[10001];
int cost[10001];
int mn[10001];

int Find(int x) {
	if(x==parent[x]) return x;
	return parent[x]=Find(parent[x]);
}

void Union(int x, int y) {
	x=Find(x);
	y=Find(y);
	
	if(x!=y) parent[y]=x;
}

int main() {
	int n,m,k;
	cin>>n>>m>>k;
	
	for(int i=1; i<=n; i++) mn[i]=0;
	for(int i=1; i<=n; i++) parent[i]=i;
	for(int i=1; i<=n; i++) cin>>cost[i];

	for(int i=0; i<m; i++) {
		int x,y;
		cin>>x>>y;
		
		if(x>y) swap(x,y);
		Union(x,y);
		
		for(int i=1; i<=n; i++) parent[i]=Find(parent[i]);
	}
	
	for(int i=1; i<=n; i++) {
		int p=parent[i];
		if(mn[p]==0 || mn[p]>cost[i]) mn[p]=cost[i];
	}
	
	int sum=0;
	for(int i=1; i<=n; i++) sum+=mn[i];
	
	if(sum<=k) cout<<sum;
	else cout<<"Oh no";
	
	return 0;
}
