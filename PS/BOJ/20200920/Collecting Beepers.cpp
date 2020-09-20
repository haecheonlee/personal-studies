#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using pi=pair<int,int>;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int X,Y;
		cin>>X>>Y;
		
		int sx,sy;
		cin>>sx>>sy;
		
		int N;
		cin>>N;
		
		
		vector<pi> a;
		a.push_back({sx,sy});
		for(int i=0; i<N; i++) {
			int x,y;
			cin>>x>>y;
		
			a.push_back({x,y});	
		}
		a.push_back({sx,sy});
		
		int adj[a.size()][a.size()];
		for(int i=0; i<a.size(); i++) {
			for(int j=i+1; j<a.size(); j++) {
				adj[i][j]=adj[j][i]=abs(a[i].first-a[j].first)+
									abs(a[i].second-a[j].second);
			}
		}
		
		vector<int> list;
		for(int i=0; i<a.size(); i++) list.push_back(i);
		
		int ans=1e9;
		do {
			int cost=0;
			for(int i=0; i<list.size()-1; i++) cost+=adj[list[i]][list[i+1]];
			ans=min(ans, cost);
		} while(next_permutation(list.begin()+1, list.end()-1));
		cout<<"The shortest path has length "<<ans<<'\n';
	}

	return 0;
}
