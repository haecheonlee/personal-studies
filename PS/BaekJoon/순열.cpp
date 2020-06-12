#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int tree_size(int n) {
	int h=(int)ceil(log2(n));
	
	return (1<<(h+1));
}

void init(vector<int> &tree, int node, int start, int end) {
	if(start==end) {
		tree[node]=1;
	} else {
		init(tree, node*2, start, (start+end)/2);
		init(tree, node*2+1, (start+end)/2+1, end);
		
		tree[node]=tree[node*2]+tree[node*2+1];
	}
}

void update(vector<int> &tree, int node, int start, int end, int i, int diff) {
	if(i>end || i<start) return;
	if(start==end) {
		tree[node]+=diff;
		return;	
	}
	
	update(tree, node*2, start, (start+end)/2, i, diff);
	update(tree, node*2+1, (start+end)/2+1, end, i, diff);
	
	tree[node]=tree[node*2]+tree[node*2+1];
}

int kth(vector<int> &tree, int node, int start, int end, int k) {
	if(start==end) return start;
	
	if(k<=tree[node*2]) return kth(tree, node*2, start, (start+end)/2, k);
	else return kth(tree, node*2+1, (start+end)/2+1, end, k-tree[node*2]);
}

int main() {
	int n;
	cin>>n;
	
	vector<int> a(n+1);
	vector<int> ans(n+1);
	vector<int> tree(tree_size(n));
	
	for(int i=1; i<=n; i++) cin>>a[i];
	
	// initialization
	init(tree, 1, 1, n);
	for(int i=1; i<=n; i++) {
		int k=a[i]+1;
		int w=kth(tree, 1, 1, n, k);
		
		ans[w]=i;
		update(tree, 1, 1, n, w, -1);
	}
	
	for(int i=1; i<=n; i++) cout<<ans[i]<<'\n';
	
	return 0;
}
