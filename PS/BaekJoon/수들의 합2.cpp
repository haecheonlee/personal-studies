#include <iostream>

using namespace std;

long long a[1000001];
long long tree[2097152];

long long sum(int node, int start, int end, int i, int j) {
	if(i>end|| j<start) return 0;
	if(i<=start && end<=j) return tree[node];
	
	return sum(node*2, start, (start+end)/2, i, j) + 
		   sum(node*2+1, (start+end)/2+1, end, i, j);
}

void update(int node, int start, int end, int i, long long diff) {
	if(i<start || i>end) return;
	
	tree[node]=tree[node]+diff;
	if(start!=end) {
		update(node*2, start, (start+end)/2, i, diff);
		update(node*2+1, (start+end)/2+1, end, i, diff);
		
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	
	while(m--) {
		int q;
		cin>>q;
		
		if(q==0) {
			// sum
			int i,j;
			cin>>i>>j;
			
			if(i>j) swap(i,j);
			cout<<sum(1, 1, n, i, j)<<'\n';
		} else {
			// modfiy
			int i,k;
			cin>>i>>k;
			
			long long diff=k-a[i];
			a[i]=k;
			
			update(1, 1, n, i, diff);
		}
	}

	return 0;
}
