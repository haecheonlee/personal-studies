#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll=long long;

const int MAX=2e3+1;
const int TREE_SIZE=1<<((int)ceil(log2(MAX))+1);

vector<int> a[MAX];
int tree[TREE_SIZE];

int query(int node, int L, int R, int i, int j) {
	if(j<L || R<i) return 0;
	if(i<=L && R<=j) return tree[node];
	
	int M=(L+R)>>1;
	return query(node*2,L,M,i,j)+query(node*2+1,M+1,R,i,j);
}

void update(int node, int L, int R, int i) {
	if(i<L || R<i) return;
	
	tree[node]+=1;
	if(L!=R) {
		int M=(L+R)>>1;
		
		update(node*2,L,M,i);
		update(node*2+1,M+1,R,i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<M; i++) {
		int x,y;
		cin>>x>>y;
		
		a[x].push_back(y);
	}
	
	ll ans=0;
	for(int x=1; x<=N; x++) {
		for(auto& y : a[x]) ans+=query(1,1,N,y+1,N);
		for(auto& y : a[x]) update(1,1,N,y);
	}
	cout<<ans;

	return 0;
}
