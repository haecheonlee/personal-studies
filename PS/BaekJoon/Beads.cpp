#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

inline int TREE_SIZE(int N) {
	return 1<<((int)ceil(log2(N))+1);
}

void update(int *tree, int node, int L, int R, int i, int diff) {
	if(i<L || R<i) return;
	
	tree[node]+=diff;
	if(L!=R) {
		int M=(L+R)/2;
		update(tree, node*2, L, M, i, diff);
		update(tree, node*2+1, M+1, R, i, diff);
	}
}

int query(int *tree, int node, int L, int R, int i, int j) {
	if(i>R || j<L) return 0;
	if(i<=L && R<=j) return tree[node];
	
	int M=(L+R)/2;
	return query(tree, node*2, L, M, i, j) + query(tree, node*2+1, M+1, R, i, j);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin>>T;
	
	while(T--) {
		int N,P,Q;
		cin>>N>>P>>Q;
		
		int tree[TREE_SIZE(N+1)];
		
		// reset
		memset(tree, 0, sizeof(tree));
		
		int total=P+Q;
		while(total--) {
			char q;
			cin>>q;
			
			if(q=='P') {
				// update
				int i,c;
				cin>>i>>c;
				
				update(tree,1,1,N,i,c);
			} else if(q=='Q') {
				// query
				int i,j;
				cin>>i>>j;
				
				cout<<query(tree,1,1,N,i,j)<<'\n';
			}
		}
	}

	return 0;
}
