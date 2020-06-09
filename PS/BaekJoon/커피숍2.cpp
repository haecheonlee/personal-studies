#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long a[100001];
long long tree[300001];

long long init(int node, int start, int end) {
	if(start==end) return tree[node]=a[start];
	else return tree[node]=init(node*2, start, (start+end)/2)+
						   init(node*2+1, (start+end)/2+1, end);
}

long long sum(int node, int start, int end, int i, int j) {
	if(i>end || j<start) return 0;
	if(i<=start && end<=j) return tree[node];
	
	return sum(node*2, start, (start+end)/2, i, j)+
		   sum(node*2+1, (start+end)/2+1, end, i, j);
}

void update(int node, int start, int end, int index, long long diff) {
	if(index<start || index>end) return;
	
	tree[node]=tree[node]+diff;
	if(start!=end) {
		update(node*2, start, (start+end)/2, index, diff);
		update(node*2+1, (start+end)/2+1, end, index, diff);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++) cin>>a[i];

	init(1,1,n);

	while(m--) {
		int x,y,p,v;
		cin>>x>>y>>p>>v;
		
		if(x>y) swap(x,y);
		
		// print
		cout<<sum(1,1,n,x,y)<<'\n';
		
		// update
		long long diff=v-a[p];
		a[p]=v;
		update(1,1,n,p,diff);
	}

	return 0;
}
