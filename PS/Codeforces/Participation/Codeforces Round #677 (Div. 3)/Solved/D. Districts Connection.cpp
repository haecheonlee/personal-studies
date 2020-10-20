#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii=pair<int,int>;

int main() {
	int T;
	cin>>T;

	while(T--) {
		int N;
		cin>>N;
		
		int a[N];
		for(int i=0; i<N; i++) cin>>a[i];
		
		vector<int> p[N];
		bool check[N];
		for(int i=0; i<N; i++) {
			check[i]=false;
	
			for(int j=0; j<N; j++) {
				if(a[i]!=a[j]) p[i].push_back(j);
			}
		}

		vector<pii> ans;

		queue<int> q;
		q.push(0);
		check[0]=true;

		while(!q.empty()) {
			int x=q.front();
			q.pop();
			
			for(auto& y : p[x]) {
				if(check[y]==false) {
					check[y]=true;
					ans.push_back({x,y});
					q.push(y);
				}
			}
		}

		if(ans.size()>=N-1) {
			cout<<"YES\n";
			for(int i=0; i<N-1; i++) cout<<ans[i].first+1<<' '<<ans[i].second+1<<'\n';
		} else {
			cout<<"NO\n";
		}
	}

	return 0;
}
