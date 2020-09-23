#include <iostream>
#include <vector>

using namespace std;

const int MAX=1e5+1;

vector<int> a[MAX];
int b[MAX];	// connected neighbors
int d[MAX];

void dfs(int x) {
	for(auto& y : a[x]) {
		if(b[y]>b[x]) {
			if(d[y]<d[x]+1) {
				d[y]=d[x]+1;
				dfs(y);	
			}
		}
	}
}

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<M; i++) {
		int u,v;
		cin>>u>>v;
		
		a[u].push_back(v);
		a[v].push_back(u);
		b[u]++, b[v]++;
	}
	
	for(int i=0; i<N; i++) {
		if(d[i]==0) {
			d[i]=1;
			dfs(i);
		}
	}
	
	int ans=0;
	for(int i=0; i<N; i++) ans=max(ans, d[i]);
	cout<<ans;
	
	return 0;
}
