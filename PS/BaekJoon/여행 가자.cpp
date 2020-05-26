#include <iostream>
#include <set>

using namespace std;

int parent[201];

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
	int n,m;
	cin>>n>>m;
	
	// setting parent
	for(int i=1; i<=n; i++) parent[i]=i;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			int x;
			cin>>x;
			
			if(i==j) continue;
			if(x==1) Union(i,j);
			for(int a=1; a<=n; a++) parent[a]=Find(a);  // update parent
		}	
	}

	set<int> result;
	while(m--) {
		int x;
		cin>>x;

		result.insert(parent[x]);
	}

	if(result.size()==1) cout<<"YES";
	else cout<<"NO";

	return 0;
}
