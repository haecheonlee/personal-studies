#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int MAX=1e6;

int tree_size(int n) {
	int h=(int)ceil(log2(n));
	
	return (1<<(h+1));
}

void update(vector<int> &tree, int node, int start, int end, int i, int diff) {
	if(i<start || i>end) return;
	
	tree[node]=tree[node]+diff;
	if(start!=end) {
		update(tree, node*2, start, (start+end)/2, i, diff);
		update(tree, node*2+1, (start+end)/2+1, end, i, diff);
	}
}

int kth(vector<int> &tree, int node, int start, int end, int k) {
	if(start==end) return start;
	else {
		if(k<=tree[node*2]) return kth(tree, node*2, start, (start+end)/2, k);
		else return kth(tree, node*2+1, (start+end)/2+1, end, k-tree[node*2]);
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
	vector<int> a(MAX+1);
	vector<int> tree(tree_size(MAX+1));
	
	int m;
	cin>>m;
	
	while(m--) {
		int q;
		cin>>q;
		
		if(q==1) {
			int k;
			cin>>k;
			
			int box=kth(tree, 1, 1, MAX, k);
			cout<<box<<'\n';
			
			a[box]-=1;
			update(tree, 1, 1, MAX, box, -1);
		} else {
			int box, diff;
			cin>>box>>diff;
			
			a[box]+=diff;
			update(tree, 1, 1, MAX, box, diff);
		}
	}
	
	return 0;
}
