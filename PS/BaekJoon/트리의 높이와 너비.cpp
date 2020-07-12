// reference: baekjoon/codeplus

#include <iostream>
#define left _left
#define right _right

using namespace std;

struct Node {
	int left, right;
	int order, depth;
};

Node a[10001];
int left[10001];
int right[10001];
int cnt[10001];
int order=0;

void in_order(int node, int depth) {
	if(node==-1) return;
	in_order(a[node].left, depth+1);
	
	a[node].order=++order;
	a[node].depth=depth;
	
	in_order(a[node].right, depth+1);
}

int main() {
	int N;
	cin>>N;
	
	for(int i=0; i<N; i++) {
		int x, y, z;
		cin>>x>>y>>z;
		
		a[x].left=y;
		a[x].right=z;
		
		if(y!=-1) cnt[y]++;
		if(z!=-1) cnt[z]++;
	}
	
	int root=0;
	for(int i=1; i<=N; i++) {
		if(cnt[i]==0) root=i;
	}
	
	in_order(root, 1);
	
	int max_depth=0;
	for(int i=1; i<=N; i++) {
		int depth=a[i].depth;
		int order=a[i].order;
		
		if(left[depth]==0) left[depth]=order;
		else left[depth]=min(left[depth], order);
		
		right[depth]=max(right[depth], order);
		max_depth=max(max_depth, depth);
	}

	int ans=0;
	int ans_level=0;
	for(int i=1; i<=max_depth; i++) {
		if(ans<right[i]-left[i]+1) {
			ans=right[i]-left[i]+1;
			ans_level=i;
		}
	}
	cout<<ans_level<<" "<<ans;
	
	return 0;
}
