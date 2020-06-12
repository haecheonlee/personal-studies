#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int tree_size(int n) {
	int h=(int)ceil(log2(n));
	
	return (1<<(h+1));
}

void init(vector<int> &tree, vector<int> &a, int node, int start, int end) {
	if(start==end) tree[node]=a[start];
	else {
		init(tree, a, node*2, start, (start+end)/2);
		init(tree, a, node*2+1, (start+end)/2+1, end);
		
		tree[node]=tree[node*2]*tree[node*2+1];
	}
}

int query(vector<int> &tree, int node, int start, int end, int l, int r) {
	if(l>end || r<start) return 1;
	if(l<=start && end<=r) return tree[node];
	
	return query(tree, node*2, start, (start+end)/2, l, r)*
		   query(tree, node*2+1, (start+end)/2+1, end, l, r);
}

void update(vector<int> &tree, int node, int start, int end, int i, int v) {
	if(i<start || i>end) return;
	if(start==end) tree[node]=v;
	else {
		update(tree, node*2, start, (start+end)/2, i, v);
		update(tree, node*2+1, (start+end)/2+1, end, i, v);
		
		tree[node]=tree[node*2]*tree[node*2+1];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	
	while(cin>>n>>m) {
		vector<int> a(n+1);
		vector<int> tree(tree_size(n));
		
		for(int i=1; i<=n; i++) {
			cin>>a[i];
			
			if(a[i]>0) a[i]=1;
			else if(a[i]<0) a[i]=-1;
		}
		
		init(tree, a, 1, 1, n);
		
		while(m--) {
			char q;
			cin>>q;
			
			if(q=='C') {
				// update
				int i,v;
				cin>>i>>v;
				
				if(v>0) v=1;
				else if(v<0) v=-1;
				
				update(tree, 1, 1, n, i, v);
			} else {
				// display
				int i,j;
				cin>>i>>j;

				int result=query(tree, 1, 1, n, i, j);
				if(result==0) cout<<0;
				else if(result>0) cout<<'+';
				else if(result<0) cout<<'-';
			}
		}
		
		cout<<'\n';
	}
	
	return 0;
}
