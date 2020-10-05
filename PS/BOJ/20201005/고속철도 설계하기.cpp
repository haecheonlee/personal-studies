#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pi=pair<int,int>;

const int MAX=2e2+1;

vector<pair<int,pi>> a;
int p[MAX];

int Find(int x) {
	if(p[x]==x) return x;
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
	
	// set parent
	for(int i=1; i<=N; i++) p[i]=i;
	int ans=0;
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			int x;
			cin>>x;

			if(i>j) continue;
			if(x<0) {
				Union(i,j);
				ans+=(abs(x));
			} else {
				a.push_back({x,{i,j}});
			}
		}
	}
	sort(a.begin(), a.end());
	
	vector<pi> road;
	for(int i=0; i<a.size(); i++) {
		int cost=a[i].first;
		int x=a[i].second.first;
		int y=a[i].second.second;
		
		if(Find(x)!=Find(y)) {
			Union(x,y);
			ans+=cost;
			road.push_back({x,y});
		}
	}
	
	cout<<ans<<' '<<road.size()<<'\n';
	for(auto& p : road) cout<<p.first<<' '<<p.second<<'\n';
	
	return 0;
}
