#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
using ll=long long;

const int MAX=1e5+1;
const int TREE_SIZE=1<<((int)ceil(log2(MAX))+1);

int tree[TREE_SIZE];

int query(int node, int L, int R, int i, int j) {
	if(j<L || R<i) return 0;
	if(i<=L && R<=j) return tree[node];
	
	int M=(L+R)>>1;
	return query(node*2, L, M, i, j) + query(node*2+1, M+1, R, i, j);
}

void update(int node, int L, int R, int i) {
	if(i<L || R<i) return;
	
	tree[node]+=1;
	if(L!=R) {
		int M=(L+R)>>1;
		
		update(node*2, L, M, i);
		update(node*2+1, M+1, R, i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin>>T;

	while(T--) {
		memset(tree, 0, sizeof(tree));
		
		int N;
		cin>>N;
		
		ll ans=0;
		for(int i=1; i<=N; i++) {
			int x;
			cin>>x;
			
			ans+=query(1, 1, N, x+1, N);
			update(1, 1, N, x);
		}
		cout<<ans<<'\n';
	}

	return 0;
}
