#include <iostream>
#include <cmath>

using namespace std;

const int MAX=1e5+1;
const int TREE_SIZE=1<<((int)ceil(log2(MAX))+1);

int a[MAX];
int ans[MAX];
int tree[TREE_SIZE];

void init(int node, int L, int R) {
	if(L==R) {
		tree[node]=1;
		return;
	}
	
	int M=(L+R)>>1;
	
	init(node*2,L,M);
	init(node*2+1,M+1,R);
	tree[node]=tree[node*2]+tree[node*2+1];
}

int kth(int node, int L, int R, int K) {
	if(L==R) return L;
	
	int M=(L+R)>>1;
	if(K<=tree[node*2]) return kth(node*2,L,M,K);
	else return kth(node*2+1,M+1,R,K-tree[node*2]);
}

void update(int node, int L, int R, int i, int v) {
	if(i<L || R<i) return;
	
	tree[node]+=v;
	if(L!=R) {
		int M=(L+R)>>1;
		update(node*2,L,M,i,v);
		update(node*2+1,M+1,R,i,v);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin>>N;
	
	for(int i=1; i<=N; i++) cin>>a[i];
	
	init(1,1,N);
	for(int i=N; i>=1; i--) {
		int K=a[i]+1;
		int w=kth(1,1,N,K);
		
		ans[w]=i;
		update(1,1,N,w,-1);
	}
	
	for(int i=N; i>=1; i--) cout<<ans[i]<<' ';
	
	return 0;
}
