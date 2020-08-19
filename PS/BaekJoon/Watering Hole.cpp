#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pi=pair<int,int>;

vector<pair<int,pi>> a;
int p[301];

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
	cin>>N;
	
	for(int i=1; i<=N; i++) {
		int cost;
		cin>>cost;
		
		a.push_back({cost, {0,i}});
	}
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			int cost;
			cin>>cost;
			
			if(i!=j) a.push_back({cost, {i,j}});
		}
	}
	
	for(int i=1; i<=N; i++) p[i]=i;
	sort(a.begin(), a.end());
	
	int ans=0;
	for(auto &p : a) {
		int cost=p.first;
		int u=p.second.first;
		int v=p.second.second;
		
		if(Find(u) != Find(v)) {
			Union(u,v);
			ans+=cost;
		}
	}
	cout<<ans;
	
	return 0;
}
