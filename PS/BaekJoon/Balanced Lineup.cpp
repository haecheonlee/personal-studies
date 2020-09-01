#include <iostream>

using namespace std;
using pi=pair<int,int>;

const int MAX=5e4+1;

int a[MAX];
pi tree[131072];

// taller
void init(int node, int L, int R) {
	if(L==R) {
		tree[node].first=a[L];
		tree[node].second=a[L];
		return;
	}
	
	int M=(L+R)/2;
	init(node*2, L, M);
	init(node*2+1, M+1, R);
	tree[node].first=max(tree[node*2].first, tree[node*2+1].first);	// tall
	tree[node].second=min(tree[node*2].second, tree[node*2+1].second);	// short
}

pi query(int node, int L, int R, int i, int j) {
	if(i>R || j<L) return make_pair(-1,-1);
	if(i<=L && R<=j) return tree[node];
	
	int M=(L+R)/2;
	pi m1=query(node*2, L, M, i, j);
	pi m2=query(node*2+1, M+1, R, i, j);
	
	if(m1.first==-1 && m1.second==-1) return m2;
	else if(m2.first==-1 && m2.second==-1) return m1;
	else {
		return make_pair(max(m1.first, m2.first), min(m1.second, m2.second));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,Q;
	cin>>N>>Q;
	
	for(int i=1; i<=N; i++) cin>>a[i];
	
	// initialization
	init(1,1,N);
	
	// print answer
	while(Q--) {
		int a,b;
		cin>>a>>b;
		
		pi ans=query(1,1,N,a,b);
		cout<<ans.first-ans.second<<'\n';
	}
	
	return 0;
}
