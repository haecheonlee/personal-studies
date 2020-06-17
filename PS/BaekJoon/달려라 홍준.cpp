#include <iostream>
#include <vector>

using namespace std;

int a[1000001];
int tree[2100000];

void init(int node, int start, int end) {
	if(start==end) tree[node]=a[start];
	else {
		init(node*2, start, (start+end)/2);
		init(node*2+1, (start+end)/2+1, end);
		tree[node]=max(tree[node*2], tree[node*2+1]);
	}
}

int query(int node, int start, int end, int left, int right) {
	if(left>end || right<start) return -1;
	if(left<=start && end<=right) return tree[node];
	
	int m1=query(node*2, start, (start+end)/2, left, right);
	int m2=query(node*2+1, (start+end)/2+1, end, left, right);
	
	if(m1==-1) return m2;
	else if(m2==-1) return m1;
	else return max(m1,m2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++) cin>>a[i];
	init(1,1,n);
	
	for(int i=m; i<=n-m+1; i++) {
		int l=i-(m-1);
		int r=i+(m-1);
		
		cout<<query(1,1,n,l,r)<<' ';
	}

	return 0;
}
