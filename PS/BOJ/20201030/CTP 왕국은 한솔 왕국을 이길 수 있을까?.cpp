#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pii=pair<int,int>;

const int MAX = 1e5 + 1;

int a[MAX], p[MAX];

int Find(int x) {
	if(p[x] == x) return x;
	return p[x] = Find(p[x]);
}

void Union(int x, int y) {
	x = Find(p[x]);
	y = Find(p[y]);
	
	if(x > y) swap(x,y);
	if(x != y) {
		a[x] += a[y];
		a[y] = 0;
		p[y] = x;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin>>N>>M;

	for(int i=1; i<=N; i++) a[i] = 1, p[i] = i;
	for(int i=0; i<M; i++) {
		int x,y;
		cin>>x>>y;
		
		Union(x,y);
	}
	
	int C,H,K;
	cin>>C>>H>>K;
	
	C = Find(p[C]), H = Find(p[H]);

	vector<pii> list;
	for(int i=1; i<=N; i++) if(a[i] > 0) list.push_back({a[i], i});
	sort(list.rbegin(), list.rend());
	
	for(int i = 0; i < (int)list.size() && K; i++) {
		int G = Find(p[list[i].second]);
		if(G != C && G != H) {
			Union(C,G);
			K--;
		}
	}
	
	cout<<a[Find(p[C])];
	
	return 0;
}
