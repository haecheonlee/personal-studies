#include <iostream>
#include <unordered_map>
#include <cmath>
#include <cstring>

using namespace std;
using ll=long long;

const int MAX=1e5+1;

int tree[1<<((int)ceil(log2(MAX))+1)];

int query(int *tree, int node, int L, int R, int i, int j) {
	if(j<L || R<i) return 0;
	if(i<=L && R<=j) return tree[node];
	
	int M=(L+R)>>1;
	return query(tree, node*2, L, M, i, j) + query(tree, node*2+1, M+1, R, i, j);
}

void update(int *tree, int node, int L, int R, int i) {
	if(i<L || R<i) return;
	
	tree[node]+=1;
	if(L!=R) {
		int M=(L+R)>>1;
		
		update(tree, node*2, L, M, i);
		update(tree, node*2+1, M+1, R, i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	while(cin>>N) {
		if(N==0) break;

		memset(tree,0,sizeof(tree));
		unordered_map<string,int> pos;
		
		for(int i=1; i<=N; i++) {
			string name;
			cin>>name;
			
			pos[name]=i;
		}
		
		// segment-tree to find the number of crossed lines
		ll ans=0;
		for(int i=0; i<N; i++) {
			string name;
			cin>>name;
			
			int position=pos[name];
			ans+=query(tree, 1, 1, N, position+1, N);
			update(tree, 1, 1, N, position);
		}
		cout<<ans<<'\n';
	}

	return 0;
}
