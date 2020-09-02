#include <iostream>
#include <cmath>

using namespace std;
using ll=long long;

const int MAX=65535;
const int SIZE=2e5+5e4+1;
const int TREE_SIZE=1<<((int)ceil(log2(SIZE))+1);

int a[SIZE];
int tree[TREE_SIZE];

void update(int node, int L, int R, int i, int v) {
	if(i<L || R<i) return;
	
	tree[node]+=v;
	if(L!=R) {
		int M=(L+R)/2;
		update(node*2, L, M, i, v);
		update(node*2+1, M+1, R, i, v);
	}
}

int kth(int node, int L, int R, int k) {
	if(L==R) return L;
	
	int M=(L+R)/2;
	if(k<=tree[node*2]) return kth(node*2, L, M, k);
	else return kth(node*2+1, M+1, R, k-tree[node*2]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,K;
	cin>>N>>K;
	
	for(int i=0; i<N; i++) cin>>a[i];
	for(int i=0; i<K-1; i++) update(1, 0, MAX, a[i], 1);
	
	ll ans=0;
	for(int i=K-1; i<N; i++) {
		update(1, 0, MAX, a[i], 1);
		ans+=(ll)kth(1, 0, MAX, (K+1)/2);
		update(1, 0, MAX, a[i-K+1], -1);
	}
	cout<<ans;
	
	return 0;
}
