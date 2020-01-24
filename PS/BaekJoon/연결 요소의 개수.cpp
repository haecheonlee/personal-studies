#include <iostream>
#include <vector>

using namespace std;

vector<int> vec[1001];
bool check[1001];

int n,m;
void dfs(int x) {
	check[x]=true;
	for(int i=0; i<vec[x].size(); i++) {
		int current=vec[x][i];
		if(check[current]==false) {
			check[current]=true;
			dfs(current);
		}
	}
}

int main() {
	cin>>n>>m;

	int u,v;
	for(int i=0; i<m; i++) {
		cin>>u>>v;
		
		vec[u].push_back(v);
		vec[v].push_back(u);
	}	

	int component=0;
	for(int i=1; i<=n; i++) {
		if(check[i]==false) {
			dfs(i);
			component+=1;
		}
	}
	cout<<component;
	return 0;
}

/*
boj.kr/11724

INPUT:
6 5
1 2
2 5
5 1
3 4
4 6

OUTPUT:
2
*/
