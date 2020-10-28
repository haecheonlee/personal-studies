#include <iostream>

using namespace std;

const int MAX=5e5+1;

int p[MAX];

int Find(int x) {
	if(p[x]==x) return x;
	return p[x]=Find(p[x]);
}

void Union(int x, int y) {
	x=Find(p[x]);
	y=Find(p[y]);
	
	p[y]=x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin>>N>>M;

	for(int i=0; i<N; i++) p[i]=i;
	for(int i=1; i<=M; i++) {
		int u,v;
		cin>>u>>v;
		
		if(Find(u)!=Find(v)) {
			Union(u,v);
		}
		else {
			cout<<i;
			return 0;	
		}
	}

	cout<<0;

	return 0;
}
