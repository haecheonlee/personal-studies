#include <iostream>
#include <vector>

using namespace std;

long long a[100001];
long long tree1[270000];

long long b[100001];
long long tree2[270000];

void init1(int node, int start, int end) {
	if(start==end) tree1[node]=a[start];
	else {
		init1(node*2, start, (start+end)/2);
		init1(node*2+1, (start+end)/2+1, end);
		
		tree1[node]=min(tree1[node*2], tree1[node*2+1]);
	}
}

long long query1(int node, int start, int end, int i, int j) {
	if(i>end || j<start) return -1;
	if(i<=start && end<=j) return tree1[node];
	
	long long m1=query1(node*2, start, (start+end)/2, i, j);
	long long m2=query1(node*2+1, (start+end)/2+1, end, i, j);
	
	if(m1==-1) return m2;
	else if(m2==-1) return m1;
	else return min(m1, m2);
}

void init2(int node, int start, int end) {
	if(start==end) tree2[node]=b[start];
	else {
		init2(node*2, start, (start+end)/2);
		init2(node*2+1, (start+end)/2+1, end);
		
		tree2[node]=max(tree2[node*2], tree2[node*2+1]);
	}
}

long long query2(int node, int start, int end, int i, int j) {
	if(i>end || j<start) return -1;
	if(i<=start && end<=j) return tree2[node];
	
	long long m1=query2(node*2, start, (start+end)/2, i, j);
	long long m2=query2(node*2+1, (start+end)/2+1, end, i, j);
	
	if(m1==-1) return m2;
	else if(m2==-1) return m1;
	else return max(m1, m2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		b[i]=a[i];
	}
	
	init1(1,1,n);
	init2(1,1,n);
	
	while(m--) {
		int i,j;
		cin>>i>>j;

		cout<<query1(1,1,n,i,j)<<" "<<query2(1,1,n,i,j)<<'\n';
	}

	return 0;
}
