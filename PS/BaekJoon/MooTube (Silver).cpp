#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX=5e3+1;

vector<int> a[MAX];
int d[MAX][MAX];
bool check[MAX];

int dfs(int x, int minimum) {
	int total=0;
	
	for(auto& y : a[x]) {
		if(check[y]==false) {
			check[y]=true;
			if(d[x][y]>=minimum) total+=dfs(y, minimum)+1;
		}
	}
	
	return total;
}

int main() {
	memset(d,-1,sizeof(d));
	
	int N,Q;
	cin>>N>>Q;
	
	for(int i=0; i<N-1; i++) {
		int u,v,c;
		cin>>u>>v>>c;

		d[u][v]=d[v][u]=c;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	for(int x=1; x<=N; x++) {
		for(auto& y : a[x]) {
			for(auto& k : a[y]) {
				if(k==x || k==y || d[x][k]!=-1) continue;
				d[x][k]=d[k][x]=min(d[x][y], d[y][k]);
			}
		}
	}
	
	while(Q--) {
		int k,v;
		cin>>k>>v;
		
		memset(check,false,sizeof(check));
		check[v]=true;
		cout<<dfs(v,k)<<'\n';
	}

	return 0;
}
