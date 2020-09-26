#include <iostream>
#include <vector>

using namespace std;

const int MAX=1e5+1;

int N,R,Q;
vector<int> a[MAX];
bool check[MAX];
int p[MAX];

int dfs(int x) {
	check[x]=true;
	
	int total=1;
	for(auto& y : a[x]) {
		if(check[y]) continue;
		total+=dfs(y);
	}
	return p[x]=total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N>>R>>Q;
	
	for(int i=0; i<N-1; i++) {
		int u,v;
		cin>>u>>v;
		
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	// check if is child
	dfs(R);

	while(Q--) {
		int x;
		cin>>x;
		
		cout<<p[x]<<'\n';
	}

	return 0;
}
