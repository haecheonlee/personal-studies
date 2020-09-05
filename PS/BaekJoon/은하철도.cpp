#include <iostream>

using namespace std;
using ll=long long;

const int MAX=1e5+1;

ll g[MAX];
int p[MAX];

int Find(int x) {
	if(p[x]==x) return x;
	return p[x]=Find(p[x]);
}

void Union(int x, int y) {
	x=Find(x);
	y=Find(y);
	
	p[x]=y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin>>N>>M;
		
	for(int i=1; i<=N; i++) p[i]=i;
	for(int i=1; i<=N; i++) cin>>g[i];
	for(int i=0; i<M; i++) {
		int a,b;
		cin>>a>>b;
		
		a=Find(a);
		b=Find(b);
		
		if(a!=b) {
			Union(a,b);
			g[b]+=g[a];
		}
		cout<<g[b]<<'\n';
	}

	return 0;
}
