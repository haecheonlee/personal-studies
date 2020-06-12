#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int tree_size(int n) {
	int h=(int)ceil(log2(n));
	int tree_size=(1<<(h+1));
	
	return tree_size;
}

int init(vector<int> &tree, vector<int> &a, int node, int start, int end) {
	if(start==end) return tree[node]=a[start];
	else {
		return tree[node]=init(tree, a, node*2, start, (start+end)/2) +
						  init(tree, a, node*2+1, (start+end)/2+1, end);
	}
}

int query(vector<int> &tree, int node, int start, int end, int l, int r) {
	if(l>end || r<start) return 0;
	if(l<=start && end<=r) return tree[node];
	
	return query(tree, node*2, start, (start+end)/2, l, r)+
		   query(tree, node*2+1, (start+end)/2+1, end, l, r);
}

void update(vector<int> &tree, int node, int start, int end, int i, int d) {
	if(i>end || i<start) return;
	
	tree[node]+=d;
	if(start!=end) {
		update(tree, node*2, start, (start+end)/2, i, d);
		update(tree, node*2+1, (start+end)/2+1, end, i, d);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	
	vector<int> tree(tree_size(n));
	vector<int> a(n+1);
	vector<int> nums(n+1);
	for(int i=1; i<=n; i++) {
		cin>>nums[i];
		
		// if even number, then 1
		if(nums[i]%2==0) a[i]=1;
	}
	
	// initialization
	init(tree, a, 1, 1, n);
	
	// query start
	int m;
	cin>>m;
	
	while(m--) {
		int q;
		cin>>q;
		
		if(q==1) {
			// update
			int i,x;
			cin>>i>>x;
			
			if(nums[i]%2==0 && x%2!=0) {
				// even to odd
				nums[i]=x;
				update(tree, 1, 1, n, i, -1);
			} else if(nums[i]%2!=0 && x%2==0) {
				// odd to even
				nums[i]=x;
				update(tree, 1, 1, n, i, 1);
			}
			
		} else if(q==2) {
			// count of even number
			int l,r;
			cin>>l>>r;
			
			cout<<query(tree, 1, 1, n, l, r)<<'\n';
		} else if(q==3) {
			// count of odd number
			int l,r;
			cin>>l>>r;
			
			cout<<(r-l+1)-query(tree, 1, 1, n, l, r)<<'\n';
		}
	}
	
	return 0;
}
