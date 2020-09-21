#include <iostream>
#include <vector>

using namespace std;

const int MAX=51;

vector<int> a[MAX];
bool adj[MAX][MAX];

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=1; i<=N; i++) adj[i][i]=true;
	for(int i=0; i<M; i++) {
		int u,v;
		cin>>u>>v;
		
		a[u].push_back(v);
		a[v].push_back(u);
		adj[u][v]=adj[v][u]=true;
	}
	
	vector<int> ans;
	while(1) {
		int cnt=0;
		vector<int> b[N+1];
		
		for(int x=1; x<=N; x++) {
			for(auto& y : a[x]) {
				// friends' friends
				for(auto& z : a[y]) {
					if(adj[x][z]==false) {
						adj[x][z]=adj[z][x]=true;
						b[x].push_back(z);
						b[z].push_back(x);
						cnt++;
					}
				}
			}
		}
		
		for(int x=1; x<=N; x++) {
			for(auto& y : b[x]) a[x].push_back(y);
		}
		
		if(cnt==0) break;
		ans.push_back(cnt);
	}
	
	cout<<ans.size()<<'\n';
	for(auto& x : ans) cout<<x<<'\n';
	
	return 0;
}
