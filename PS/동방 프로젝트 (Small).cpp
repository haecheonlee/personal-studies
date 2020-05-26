#include <iostream>
#include <set>

using namespace std;

int parent[101];

int Find(int x) {
	if(x==parent[x]) return x;
	else return parent[x]=Find(parent[x]);
}

void Union(int x, int y) {
	x=Find(x);
	y=Find(y);
	
	if(x!=y) parent[y]=x;
}


int main() {
	int n,m;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++) parent[i]=i;
	
	while(m--) {
		int x,y;
		cin>>x>>y;
		
		for(int i=x+1; i<=y; i++) Union(x,i);
		for(int i=1; i<=n; i++) parent[i]=Find(i);
	}

	set<int> result;
	for(int i=1; i<=n; i++) result.insert(parent[i]);
	cout<<result.size();
	
	return 0;
}
