#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX=2e3+5e2+1;

vector<int> a[MAX];
bool check[MAX];
bool d[MAX][MAX];

void dfs(int x, int parent) {
	check[x]=true;
	
	for(auto& y : a[x]) {
		if(check[y]==false) {
			d[parent][y]=true;
			dfs(y, parent);
		}
	}
}

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N,M;
		cin>>N>>M;
		
		memset(check, false, sizeof(check));
		memset(d, 0, sizeof(d));
		for(int i=1; i<=N; i++) a[i].clear();
		
		for(int i=0; i<M; i++) {
			int u,v;
			cin>>u>>v;
			
			d[u][v]=true;
			a[u].push_back(v);
		}
		
		for(int x=1; x<=N; x++) {
			memset(check, false, sizeof(check));
			check[x]=true;
			for(auto& y : a[x]) dfs(y,x);
		}
		
		int ans=0;
		for(int x=1; x<=N; x++) {
			for(int y=1; y<=N; y++) {
				if(x==y) continue;
				if(d[x][y]) ans++;
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}
