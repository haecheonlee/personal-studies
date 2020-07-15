#include <iostream>

using namespace std;

int a[100001];
int tree[270000];

void init(int node, int L, int R) {
	if(L==R) {
		tree[node]=L;
		return;
	}
	
	int M=(L+R)/2;
	init(node*2, L, M);
	init(node*2+1, M+1, R);
	
	if(a[tree[node*2]]<=a[tree[node*2+1]]) tree[node]=tree[node*2];
	else tree[node]=tree[node*2+1];
}

void update(int node, int L, int R, int i, int v) {
	if(i<L || R<i) return;
	if(L==R) {
		a[i]=v;
		return;
	}
	
	int M=(L+R)/2;
	update(node*2, L, M, i, v);
	update(node*2+1, M+1, R, i, v);
	
	if(a[tree[node*2]]<=a[tree[node*2+1]]) tree[node]=tree[node*2];
	else tree[node]=tree[node*2+1];
}

int query(int node, int L, int R, int i, int j) {
	if(i>R || j<L) return -1;
	if(i<=L && R<=j) return tree[node];
	
	int M=(L+R)/2;
	int m1=query(node*2,L,M,i,j);
	int m2=query(node*2+1,M+1,R,i,j);
	
	if(m1==-1) return m2;
	else if(m2==-1) return m1;
	else {
		if(a[m1]<=a[m2]) return m1;
		else return m2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin>>N;
	
	for(int i=1; i<=N; i++) cin>>a[i];
	init(1,1,N);

	int M;
	cin>>M;
	
	while(M--) {
		int x;
		cin>>x;
		
		if(x==1) {
			// a[i]=v
			int i,v;
			cin>>i>>v;
			
			a[i]=v;
			update(1,1,N,i,v);
		} else {
			// min of (a[i],a[j])
			int i,j;
			cin>>i>>j;
			
			cout<<query(1,1,N,i,j)<<'\n';
		}
	}

	return 0;
}
