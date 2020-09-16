#include <iostream>
#include <set>

using namespace std;

const int MAX=3e5+1;

int p[MAX];

int Find(int x) {
	if(x==p[x]) return x;
	return p[x]=Find(p[x]);
}

void Union(int x, int y) {
	x=Find(p[x]);
	y=Find(p[y]);
	
	if(x!=y) p[y]=x;
}

int main() {
	int N;
	cin>>N;

	for(int i=1; i<=N; i++) p[i]=i;
	for(int i=0; i<N-2; i++) {
		int u,v;
		cin>>u>>v;
		
		Union(u,v);
	}
	
	set<int> ans;
	for(int i=1; i<=N; i++) ans.insert(Find(p[i]));
	for(auto it : ans) cout<<it<<' ';

	return 0;
}
