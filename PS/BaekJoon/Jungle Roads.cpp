#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pi=pair<int,int>;

vector<pair<int,pi>> a;
int p[26];

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
	int N;

	while(cin>>N) {
		if(N==0) break;
		
		// initialization
		for(int i=0; i<N; i++) p[i]=i;
		a.clear();
		
		for(int i=0; i<N-1; i++) {
			char from;
			int k;
			cin>>from>>k;

			while(k--) {
				char to;
				int cost;
				cin>>to>>cost;

				a.push_back({cost, {from-'A', to-'A'}});
			}
		}

		sort(a.begin(), a.end());
		int ans=0;
		for(auto& p : a) {
			int cost=p.first;
			int u=p.second.first;
			int v=p.second.second;
			
			if(Find(u) != Find(v)) {
				Union(u,v);
				ans+=cost;
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}
