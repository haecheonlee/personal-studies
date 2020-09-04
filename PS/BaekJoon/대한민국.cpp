/* reference: https://jason9319.tistory.com/230 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
using pi=pair<int,int>;
using ll=long long;

const int MAX=1e3+1;
const int TREE_SIZE=1<<((int)ceil(log2(MAX))+1);

int tree[TREE_SIZE];

ll query(int node, int L, int R, int i, int j) {
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
	int T;
	scanf("%d", &T);
	
	for(int tc=1; tc<=T; tc++) {
		memset(tree, 0, sizeof(tree));
		
		int N,M,K;
		scanf("%d %d %d", &N, &M, &K);

		vector<pi> a;
		for(int i=0; i<K; i++) {
			int x,y;
			scanf("%d %d", &x, &y);
			
			a.push_back({x,y});
		}
		sort(a.begin(), a.end());
		
		ll ans=0;
		for(auto& p : a) {
			ans+=query(1, 1, max(N,M)+1, p.second+1, max(N,M)+1);
			update(1, 1, max(N,M)+1, p.second);
		}
		printf("Test case %d: %lld\n", tc, ans);
	}

	return 0;
}
