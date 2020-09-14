#include <iostream>
#include <vector>

using namespace std;

const int MAX=21;

vector<int> a[MAX];
int d[MAX];

void dfs(int x) {
	for(auto& y : a[x]) {
		if(d[y]==0) {
			d[y]=d[x]+1;
			dfs(y);
		}
	}
}

int main() {
	int N;
	cin>>N;
	
	int root=0;
	for(int i=1; i<=N; i++) {
		int p;
		cin>>p;
		
		if(p==-1) root=i;
		else a[p].push_back(i);
	}
	
	d[root]=1;
	dfs(root);
	
	for(int i=1; i<=N; i++) cout<<d[i]-1<<'\n';
	
	return 0;
}
