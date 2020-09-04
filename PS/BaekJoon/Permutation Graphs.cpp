#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
using ll=long long;

const int MAX=1e5+1;
const int TREE_SIZE=1<<((int)ceil(log2(MAX))+1);

int N;
int a[MAX];
int tree[TREE_SIZE];

ll query(int x) {
	ll ans=0;
	for(int i=x; i>0; i-=(i&-i)) ans+=tree[i];	
	return ans;
}

void update(int x) {
	for(int i=x; i<=N; i+=(i&-i)) tree[i]+=1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;
	
	while(T--) {
		memset(tree, 0, sizeof(tree));
		cin>>N;
		
		for(int i=1; i<=N; i++) {
			int x;
			cin>>x;
			
			a[x]=i;
		}
		
		ll ans=0;
		for(int i=0; i<N; i++) {
			int x;
			cin>>x;
			
			ans+=(query(N) - query(a[x]));
			update(a[x]);
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
