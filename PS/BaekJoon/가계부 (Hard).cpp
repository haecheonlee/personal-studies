#include <iostream>

using namespace std;
using ll=long long;

const int MAX=1e6+1;
const int TREE_SIZE=2097152;	// 1<<(log2(MAX))

ll a[MAX];
ll tree[TREE_SIZE];

void update(int node, int L, int R, int i, ll diff) {
	if(i<L || R<i) return;
	
	tree[node]+=diff;
	if(L!=R) {
		int M=(L+R)/2;
		update(node*2, L, M, i, diff);
		update(node*2+1, M+1, R, i, diff);
	}
}

ll query(int node, int L, int R, int i, int j) {
	if(j<L || R<i) return 0;
	if(i<=L && R<=j) return tree[node];
	
	int M=(L+R)/2;
	return query(node*2, L, M, i, j) + query(node*2+1, M+1, R, i, j);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,Q;
	cin>>N>>Q;
	
	while(Q--) {
		int q;
		cin>>q;
		
		if(q==1) {
			// update
			int p,x;
			cin>>p>>x;
			
			a[p]+=x;
			update(1,1,N,p,x);
		} else if(q==2) {
			// query
			int p,q;
			cin>>p>>q;
			
			cout<<query(1,1,N,p,q)<<'\n';
		}
	}
	
	return 0;
}
