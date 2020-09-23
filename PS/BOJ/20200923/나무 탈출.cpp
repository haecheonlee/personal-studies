#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX=5e5+1;

vector<int> a[MAX];
vector<int> leaf;
int d[MAX];

void dfs(int x) {
	for(auto& y : a[x]) {
		if(d[y]==-1) {
			d[y]=d[x]+1;
			dfs(y);
		}
	}
}

int main() {
	int N;
	cin>>N;
	
	for(int i=0; i<N-1; i++) {
		int u,v;
		cin>>u>>v;
		
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	for(int i=1; i<=N; i++) {
		if(a[i].size()==1) leaf.push_back(i);
	}

	memset(d, -1, sizeof(d));
	d[1]=0;
	dfs(1);

	int total=0;
	for(auto& x : leaf) total+=d[x];

	cout<<((total%2) ? "Yes" : "No");

	return 0;
}
