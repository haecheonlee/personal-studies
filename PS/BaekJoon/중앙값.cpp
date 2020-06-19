#include <iostream>

using namespace std;
const int MAX=65535;

int a[250001];
int tree[270000];

void update(int node, int start, int end, int i, int v) {
	if(i>end || i<start) return;
	
	if(start==end) {
		tree[node]+=v;
		return;
	}
	
	int mid=(start+end)/2;
	update(node*2, start, mid, i, v);
	update(node*2+1, mid+1, end, i, v);
		
	tree[node]=tree[node*2]+tree[node*2+1];
}

int kth(int node, int start, int end, int k) {
	if(start==end) return start;
	
	int mid=(start+end)/2;
	if(k<=tree[node*2]) return kth(node*2, start, mid, k);
	else return kth(node*2+1, mid+1, end, k-tree[node*2]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,k;
	cin>>n>>k;
	
	for(int i=0; i<n; i++) cin>>a[i];
	for(int i=0; i<k-1; i++) update(1,0,MAX,a[i],1);
	
	long long ans=0;
	for(int i=k-1; i<n; i++) {
		update(1,0,MAX,a[i],1);
		ans+=(long long)kth(1,0,MAX,(k+1)/2);
		update(1,0,MAX,a[i-k+1],-1);
	}
	cout<<ans;

	return 0;
}
