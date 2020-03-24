#include <iostream>
#include <vector>

using namespace std;

int n,p,r,root;
vector<int> children[51];

int dfs(int idx) {
	int cnt=0;
	if(idx==r) return 0;
	else if(children[idx].empty() || 
		   (children[idx][0]==r && children[idx].size()==1)) return 1;
	else for(int child : children[idx]) cnt+=dfs(child);
	
	return cnt;
}

int main() {
	cin>>n;
	
	for(int i=0; i<n; i++) {
		cin>>p;
		if(p==-1) root=i;
		else children[p].push_back(i);
	}
	
	cin>>r;

	cout<<dfs(root);

	return 0;
}

/*
INPUT:
5
-1 0 0 1 1
2

OUTPUT:
2
*/
