#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using pi=pair<int,int>;

void init(vector<pi> &tree, vector<pi> &a, int node, int start, int end) {
	if(start==end) tree[node]=a[start];
	else {
		init(tree, a, node*2, start, (start+end)/2);
		init(tree, a, node*2+1, (start+end)/2+1, end);
		tree[node]=min(tree[node*2], tree[node*2+1]);
	}
}

void update(vector<pi> &tree, int node, int start, int end, int i, int v) {
	if(i<start || i>end) return;
	if(start==end) {
		tree[node]=make_pair(v,i);
	} else {
		update(tree, node*2, start, (start+end)/2, i, v);
		update(tree, node*2+1, (start+end)/2+1, end, i, v);
		tree[node]=min(tree[node*2], tree[node*2+1]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	
	vector<pi> a(n);
	for(int i=0; i<n; i++) {
		int x;
		cin>>x;
		
		a[i]=make_pair(x,i);
	}
	
	int h=(int)ceil(log2(n));
	int tree_size=(1<<(h+1));
	vector<pi> tree(tree_size);
	
	init(tree, a, 1, 0, n-1);
	
	// query
	int m;
	cin>>m;
	
	while(m--) {
		int q;
		cin>>q;
		
		if(q==1) {
			int i,v;
			cin>>i>>v;
			
			i-=1;
			update(tree, 1, 0, n-1, i, v);
		} else {
			// display index which contains the smallest num in list
			cout<<tree[1].second+1<<'\n';
		}
	}

	return 0;
}
