#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void init(vector<int> &tree, vector<int> &a, int node, int start, int end) {
	if(start==end) tree[node]=a[start];
	else {
		init(tree, a, node*2, start, (start+end)/2);
		init(tree, a, node*2+1, (start+end)/2+1, end);
		tree[node]=min(tree[node*2], tree[node*2+1]);
	}
}

int query(vector<int> &tree, int node, int start, int end, int i, int j) {
	if(i>end || j<start) return -1;
	if(i<=start && end<=j) return tree[node];
	
	int m1=query(tree, node*2, start, (start+end)/2, i, j);
	int m2=query(tree, node*2+1, (start+end)/2+1, end, i, j);
	
	if(m1==-1) return m2;
	else if(m2==-1) return m1;
	else return min(m1, m2);
}

void update(vector<int> &tree, int node, int start, int end, int i, int v) {
	if(i<start || end<i) return;
	if(start==end) {
		tree[node]=v;
		return;
	}
	
	update(tree, node*2, start, (start+end)/2, i, v);
	update(tree, node*2+1, (start+end)/2+1, end, i, v);
	tree[node]=min(tree[node*2], tree[node*2+1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	
	vector<int> a(n+1);
	for(int i=1; i<=n; i++) cin>>a[i];
	
	/* tree initialization */
	int h=(int)ceil(log2(n));
	int tree_size=(1<<(h+1));
	vector<int> tree(tree_size);
	
	init(tree, a, 1, 1, n);
	
	/* query */
	int m;
	cin>>m;

	while(m--) {
		int q;
		cin>>q;
		
		
		if(q==1) {
			//update
			int i,v;
			cin>>i>>v;
			
			update(tree, 1, 1, n, i, v);
		} else {
			// print
			int i,j;
			cin>>i>>j;
			
			cout<<query(tree, 1, 1, n, i, j)<<'\n';
		}
	}
	
	return 0;
}
