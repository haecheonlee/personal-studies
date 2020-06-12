#include <iostream>
#include <vector>

using namespace std;

int l=0;
void update(vector<int> &tree, int i, int diff) {
	while(i<=l) {
		tree[i]+=diff;
		i+=(i&-i);
	}
}

int sum(vector<int> &tree, int i) {
	int ans=0;
	while(i>0) {
		ans+=tree[i];
		i-=(i&-i);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin>>t;
	
	while(t--) {
		int n,m;
		cin>>n>>m;
		
		vector<int> tree(n+m+1);
		vector<int> position(n+1);
		
		l=n+m;
		for(int i=1; i<=n; i++) {
			update(tree, m+i, 1);
			position[i]=m+i;
		}
		
		for(int i=m; i>=1; i--) {
			int x;
			cin>>x;
			
			cout<<sum(tree, position[x]-1)<<" ";
			update(tree, position[x], -1);
			position[x]=i;
			update(tree, position[x], 1);
		}
		cout<<'\n';
	}
	
	return 0;
}
