#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a[100000];
int order[100000];
bool check[100000];

bool cmp(const int &x, const int &y) {
	return order[x]<order[y];
}

void dfs(int x, vector<int> &dfs_order) {
	check[x]=true;
	dfs_order.push_back(x);
	for(auto y : a[x]) {
		if(check[y]) continue;
		dfs(y,dfs_order);
	}
}

int main() {
	int N;
	cin>>N;
	
	for(int i=0; i<N-1; i++) {
		int x,y;
		cin>>x>>y;
		
		x-=1;
		y-=1;
		
		a[x].push_back(y);
		a[y].push_back(x);
	}
	
	vector<int> d(N);
	for(int i=0; i<N; i++) {
		cin>>d[i];
		
		d[i]-=1;
		order[d[i]]=i;
	}
	
	// sort by order 
	for(int i=0; i<N; i++) sort(a[i].begin(), a[i].end(), cmp);
	
	vector<int> dfs_order;
	for(int i=0; i<N; i++) {
		if(check[i]==false) {
			dfs(i, dfs_order);
		}
	}
	
	if(dfs_order==d) cout<<1;
	else cout<<0;
	
	return 0;
}
