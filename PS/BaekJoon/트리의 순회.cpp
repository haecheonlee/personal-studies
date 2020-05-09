#include <iostream>

using namespace std;

int inorder[100000];
int postorder[100000];
int position[100001];

void solve(int in_start, int in_end, int post_start, int post_end) {
	if(in_start>in_end || post_start>post_end) return;
	
	int root=postorder[post_end];
	cout<<root<<" ";
	int p=position[root];
	
	// how many nodes for left and right
	int left=p-in_start;
	int right=in_end-p;
	
	solve(in_start, p-1, post_start, post_start+left-1);
	solve(p+1, in_end, post_start+left, post_start+left+right-1);
}

int main() {
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++) cin>>inorder[i];
	for(int i=0; i<n; i++) cin>>postorder[i];
	for(int i=0; i<n; i++) position[inorder[i]]=i;

	solve(0,n-1,0,n-1);

	return 0;
}

/*
INPUT:
3
1 2 3
1 3 2

OUTPUT:
2 1 3
*/
