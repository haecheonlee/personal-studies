#include <iostream>

using namespace std;

const int MOD=1e9+7;
const int TREE_SIZE=3e6;

int a[1000001];
int tree[TREE_SIZE];

int init(int node, int L, int R) {
	if(L==R) return tree[node]=a[L];
	else {
		int M=(L+R)/2;
		return tree[node]=(1LL*init(node*2,L,M)*init(node*2+1,M+1,R))%MOD;
	}
}

int update(int node, int L, int R, int i, int v) {
	if(L>i || i>R) return tree[node];
	if(L==R) return tree[node]=v;

	int M=(L+R)/2;
	return tree[node]=(1LL*update(node*2,L,M,i,v)*update(node*2+1,M+1,R,i,v))%MOD;
}

int query(int node, int L, int R, int i, int j) {
	if(i>R || j<L) return 1;
	if(i<=L && R<=j) return tree[node];
	
	int M=(L+R)/2;
	return (1LL*query(node*2,L,M,i,j)*query(node*2+1,M+1,R,i,j))%MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	for(int i=0; i<=TREE_SIZE; i++) tree[i]=1;
	
	int N,M,K;
	cin>>N>>M>>K;
	
	for(int i=1; i<=N; i++) cin>>a[i];
	init(1,1,N);

	for(int i=0; i<M+K; i++) {
		int x,b,c;
		cin>>x;
		
		if(x==1) {
			// a[b]=c;
			cin>>b>>c;
			update(1,1,N,b,c);
		} else {
			// sum of multiplication [b] to [c]
			cin>>b>>c;
			cout<<query(1,1,N,b,c)<<'\n';
		}
	}
	
	return 0;
}
