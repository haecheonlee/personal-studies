#include <iostream>

using namespace std;

int a[500001];
int tree[1050000];

int init(int node, int start, int end) {
	if(start==end) return tree[node]=a[start];
	else {
		return tree[node]=init(node*2, start, (start+end)/2)+
						  init(node*2+1, (start+end)/2+1, end);
	}
}

void update(int node, int start, int end, int i, int v) {
	if(i>end || i<start) return;
	
	tree[node]+=v;
	if(start!=end) {
		update(node*2, start, (start+end)/2, i, v);
		update(node*2+1, (start+end)/2+1, end, i, v);
	}
}

int kth(int node, int start, int end, int k) {
	if(start==end) return start;
	else {
		if(k<=tree[node*2]) return kth(node*2, start, (start+end)/2, k);
		else return kth(node*2+1, (start+end)/2+1, end, k-tree[node*2]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin>>n;
	
	for(int i=1; i<=n; i++) cin>>a[i];
	init(1,1,n);
	
	int m;
	cin>>m;
	
	while(m--) {
		int q;
		cin>>q;
		
		if(q==1) {
			int i,v;
			cin>>i>>v;
			update(1,1,n,i,v);
		} else if(q==2) {
			int k;
			cin>>k;

			cout<<kth(1,1,n,k)<<'\n';
		}
	}
	
	return 0;
}
