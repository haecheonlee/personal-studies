#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const int MAX = 1e5 + 1;

int p[MAX], s[MAX];

int Find(int x) {
	if(p[x] == x) return x;
	return p[x] = Find(p[x]);
}

void Union(int x, int y) {
	x = Find(p[x]);
	y = Find(p[y]);
	
	
	if(x != y) {
		s[x] += s[y];
		s[y] = 0;
		p[y] = x;
	}
}

void Fight(int x, int y) {
	x = Find(p[x]);
	y = Find(p[y]);
	
	if(x != y) {
		if (s[x] > s[y]) s[x] -= s[y], s[y] = 0, p[y] = x;
		else if (s[x] < s[y]) s[y] -= s[x], s[x] = 0, p[x] = y;
		else s[x] = s[y] = 0, p[x] = p[y] = 0;
	}
}

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=1; i<=N; i++) cin>>s[i];
	for(int i=1; i<=N; i++) p[i] = i;
	
	while(M--) {
		int O,P,Q;
		cin>>O>>P>>Q;
		
        // always P < Q
        if(p[Find(P)] < p[Find(Q)]) swap(P,Q);
        
		if(O==1) {
			// union
			Union(P,Q);
		} else {
			// fight
			Fight(P,Q);
		}
	}
	
	vector<int> ans;
	for(int i=1; i<=N; i++) if(s[i] > 0) ans.push_back(s[i]);
	sort(ans.begin(), ans.end());
	
	cout<<ans.size()<<'\n';
	for(auto& x : ans) cout<<x<<' ';

	return 0;
}
