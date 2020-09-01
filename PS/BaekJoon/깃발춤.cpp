#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
using ll=long long;
using pi=pair<ll,ll>;

const int MAX=3e5+1;
const int TREE_SIZE=1<<((int)ceil(log2(MAX))+1);

int a[MAX];
pi tree[TREE_SIZE];	// {odd, even}

void init(int node, int L, int R) {
	if(L==R) {
		if(L%2==0) {
			// node number = even
			tree[node].first=0;
			tree[node].second=a[L];
		} else {
			// node number = odd
			tree[node].first=a[L];
			tree[node].second=0;
		}
		
		return;
	}
	
	int M=(L+R)/2;
	init(node*2, L, M);
	init(node*2+1, M+1, R);

	tree[node].first=tree[node*2].first + tree[node*2+1].first;
	tree[node].second=tree[node*2].second + tree[node*2+1].second;
}

pi query(int node, int L, int R, int i, int j) {
	if(j<L || R<i) return make_pair(-1,-1);
	if(i<=L && R<=j) return tree[node];
	
	int M=(L+R)/2;
	pi m1=query(node*2, L, M, i, j);
	pi m2=query(node*2+1, M+1, R, i, j);
	
	if(m1.first==-1 && m1.second==-1) return m2;
	else if(m2.first==-1 && m2.second==-1) return m1;
	else return make_pair(m1.first + m2.first, m1.second + m2.second);
}

void update(int node, int L, int R, int i, int x) {
	if(L>i || R<i) return;
	
	if(i%2==0) tree[node].second+=x;
	else tree[node].first+=x;
	
	if(L!=R) {
		int M=(L+R)/2;
		update(node*2, L, M, i, x);
		update(node*2+1, M+1, R, i, x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,Q;
	cin>>N>>Q;
	
	// initialization
	for(int i=1; i<=N; i++) cin>>a[i];
	init(1,1,N);

	while(Q--) {
		int q;
		cin>>q;
		
		if(q==1) {
			// query
			int i,j;
			cin>>i>>j;
			
			pi ans=query(1,1,N,i,j);
			cout<<abs(ans.first - ans.second)<<'\n';
		} else if(q==2) {
			// update
			int i,x;
			cin>>i>>x;
			
			update(1,1,N,i,x);
		}
	}
	
	return 0;
}
