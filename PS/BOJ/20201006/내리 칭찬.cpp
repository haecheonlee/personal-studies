#include <iostream>
#include <vector>

using namespace std;

const int MAX=1e5+1;

vector<int> a[MAX];
int p[MAX], ans[MAX];

void dfs(int x) {
	ans[x]+=p[x];
	for(auto& y : a[x]) p[y]+=p[x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin>>N>>M;
	
	for(int i=1; i<=N; i++) {
		int x;
		cin>>x;
		if(x!=-1) a[x].push_back(i);
	}

	for(int i=0; i<M; i++) {
		int x,c;
		cin>>x>>c;
		
		p[x]+=c;
	}
	
	for(int x=1; x<=N; x++) {
		if(p[x]==0) continue;
		dfs(x);
	}
	
	for(int i=1; i<=N; i++) cout<<ans[i]<<' ';

	return 0;
}
