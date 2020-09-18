#include <iostream>
#include <vector>
#include <set>

using namespace std;
using pi=pair<int,int>;

const int MAX=3e3+1;

vector<pair<pi,int>> a;
int p[MAX];

bool is_possble_to_reach(auto& u, auto& v) {
	int x=abs(u.first.first-v.first.first);
	int y=abs(u.first.second-v.first.second);
	int l=(x*x)+(y*y);
	int c=u.second+v.second;
	
	return l<=(c*c);
}

int Find(int x) {
	if(p[x]==x) return x;
	return p[x]=Find(p[x]);
}

void Union(int x, int y) {
	x=Find(x);
	y=Find(y);
	
	if(x!=y) p[y]=x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		// reset parent
		for(int i=1; i<=N; i++) p[i]=i;
		
		a.resize(N+1);
		for(int i=1; i<=N; i++) {
			cin>>a[i].first.first>>a[i].first.second>>a[i].second;
		}
		
		for(int i=1; i<=N; i++) {
			for(int j=i+1; j<=N; j++) {
				if(is_possble_to_reach(a[i], a[j])) Union(i,j);
			}
		}
		
		set<int> ans;
		for(int i=1; i<=N; i++) ans.insert(Find(p[i]));
		cout<<ans.size()<<'\n';
	}

	return 0;
}
