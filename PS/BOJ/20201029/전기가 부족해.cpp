#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii=pair<int,int>;

const int MAX=1e3 + 1;

vector<pair<int,pii>> a;
vector<int> power;
int p[MAX];

int Find(int x) {
	if(p[x]==x) return x;
	return p[x] = Find(p[x]);
}

void Union(int x, int y) {
	x = Find(p[x]);
	y = Find(p[y]);

	if(x != y) {
		p[y] = x;
	}
}

int main() {
	int N,M,K;
	cin>>N>>M>>K;

	power.resize(K);	
	for(int i=0; i<K; i++) cin>>power[i];

	for(int i=0; i<M; i++) {
		int u,v,c;
		cin>>u>>v>>c;
	
		a.push_back({c,{u,v}});
	}
	sort(a.begin(), a.end());

	for(int i=1; i<=N; i++) p[i] = i;
	for(int i=1; i<K; i++) Union(power[i-1], power[i]);


	int ans = 0;
	for(int i=0; i<M; i++) {
		int c = a[i].first;
		int x = a[i].second.first;
		int y = a[i].second.second;

		if(Find(x) != Find(y)) {
			Union(x,y);
			ans += c;
		}
	}
	cout<<ans;

	return 0;
}
