#include <iostream>

using namespace std;

int parent[1000001];
int ranks[1000001];

int Find(int x) {
	if(x==parent[x]) return x;
	else return parent[x]=Find(parent[x]);
}

void Union(int x, int y) {
	x=Find(x);
	y=Find(y);
	
	if(x==y) return;
	if(ranks[x]<ranks[y]) swap(x,y);
	parent[y]=x;
	if(ranks[x]==ranks[y]) ranks[x]=ranks[y]+1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=0; i<=n; i++) {
		parent[i]=i;
		ranks[i]=0;
	}
	
	while(m--) {
		int w,x,y;
		cin>>w>>x>>y;
		
		if(w==0) {
			Union(x,y);
		} else {
			if(Find(x)==Find(y)) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}

	return 0;
}

/*
INPUT:
7 8
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1

OUTPUT:
NO
NO
YES
*/
