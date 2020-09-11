#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX=1e5+1;

int N,S,D;
vector<int> a[MAX];
int d[MAX];		// max depth of parent
bool check[MAX];

// the max_depth from (x) node
int init(int x, int depth) {
	check[x]=true;

	int max_depth=depth;
	for(auto& y : a[x]) {
		if(check[y]==false) {
			max_depth=max(max_depth, init(y, depth+1));
		}
	}
	
	d[x]=max_depth-depth;
	return max_depth;
}

int dfs(int x) {
	check[x]=true;

	int cost=0;
	for(auto& y : a[x]) {
		if(check[y]==false && d[y]>=D) {
			cost+=dfs(y)+2;
		}
	}
	return cost;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N>>S>>D;

	for(int i=0; i<N-1; i++) {
		int x,y;
		cin>>x>>y;
		
		a[x].push_back(y);
		a[y].push_back(x);
	}
	
	init(S,0);
	memset(check, false, sizeof(check));
	cout<<dfs(S);
	
	return 0;
}
