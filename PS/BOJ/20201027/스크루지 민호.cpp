/* reference: https://www.weeklyps.com/entry/%ED%8A%B8%EB%A6%AC%EC%9D%98-%EC%A7%80%EB%A6%84 */

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX=1e5 + 1;

vector<int> a[MAX];
int d[MAX], d2[MAX], far[MAX]; 
bool check[MAX];

void dist_dfs(int x) {
	check[x] = true;

	for(auto& y : a[x]) {
		if(check[y]==false) {
			dist_dfs(y);
			
			if(d[y] + 1 > d[x]) {
				d2[x] = d[x];
				d[x] = d[y] + 1;
			} else if(d[y] + 1 > d2[x]) {
				d2[x] = d[y] + 1;
			}
		}
	}
}

void far_dfs(int x, int parent) {
	check[x] = true;
	far[x] = max(d[x], parent);
	
	for(auto& y : a[x]) {
		if(check[y] == false) {
			if(d[x] == d[y] + 1) far_dfs(y, max(parent + 1, d2[x] + 1));
			else far_dfs(y, max(parent + 1, d[x] + 1));
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
	
	dist_dfs(1);
	memset(check, false, sizeof(check));
	far_dfs(1,0);
	
	int ans=1e9;
	for(int i=1; i<=N; i++) ans=min(ans, far[i]);
	cout<<ans;
	
	return 0;
}
