#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int a[100001];
long long tree[270000];
int n;

void init(int node, int start, int end) {
	if(start==end) tree[node]=1;
	else {
		int mid=(start+end)/2;
		
		init(node*2, start, mid);
		init(node*2+1, mid+1, end);
		
		tree[node]+=tree[node*2]+tree[node*2+1];
	}
}

long long sum(int node, int start, int end, int i, int j) {
	if(i>end || j<start) return 0;
	if(i<=start && end<=j) return tree[node];
	
	int mid=(start+end)/2;
	return sum(node*2,start,mid,i,j)+sum(node*2+1,mid+1,end,i,j);
}

void update(int node, int start, int end, int i) {
	if(i>end || i<start) return;
	
	tree[node]-=1;
	if(start!=end) {
		int mid=(start+end)/2;
		
		update(node*2, start, mid, i);
		update(node*2+1, mid+1, end, i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n;

	vector<int> p(n+1);
	map<int,int> pos;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		pos[a[i]]=i;
	}
	
	init(1,1,n);
	
	// segment tree
	long long ans=0;
	int s=1, e=n;
	for(int i=1; i<=n; i++) {
		if(i%2==0) {
			// from n..1
			ans=sum(1,1,n,pos[e]+1,n);
			update(1,1,n,pos[e]);
			cout<<ans<<'\n';

			e--;
		} else {
			// from 1..n
			ans=sum(1,1,n,1,pos[s]-1);
			update(1,1,n,pos[s]);
			cout<<ans<<'\n';
			
			s++;
		}
	}
	
	return 0;
}
