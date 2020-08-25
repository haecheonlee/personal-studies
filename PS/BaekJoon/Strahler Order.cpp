#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int ind[1001];
int level[1001];
bool check[1100];

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int K,M,P;
		cin>>K>>M>>P;
		
		vector<int> a[M+1];
		memset(ind,0,sizeof(ind));
		memset(level,0,sizeof(level));
		memset(check,false,sizeof(check));
		
		for(int i=0; i<P; i++) {
			int u,v;
			cin>>u>>v;
			
			ind[v]++;
			a[u].push_back(v);
		}
		
		queue<int> q;
		for(int i=1; i<=M; i++) {
			if(ind[i]==0) {
				level[i]=1;
				q.push(i);
			}
		}
		
		while(!q.empty()) {
			int x=q.front();
			q.pop();

			for(auto& y : a[x]) {
				ind[y]--;
				
				if(level[x]>level[y]) {
					level[y]=level[x];
					check[level[x]]=true;
				} else if(level[x]==level[y]) {
					if(check[level[x]]) level[y]=level[x]+1;
				}
				
				if(ind[y]==0) q.push(y);
			}
		}

		int ans=0;
		for(int i=1; i<=M; i++) ans=max(ans,level[i]);
		cout<<K<<' '<<ans<<'\n';
	}

	return 0;
}
