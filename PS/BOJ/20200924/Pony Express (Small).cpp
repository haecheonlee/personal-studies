#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
#include <iomanip>

using namespace std;
using pi=pair<int,int>;

const double INF=1e9;

int main() {
	int T;
	cin>>T;
	
	for(int tc=1; tc<=T; tc++) {
		int N,Q;
		cin>>N>>Q;
		
		pi p[N+1];		
		for(int i=1; i<=N; i++) {
			cin>>p[i].first>>p[i].second;
		}
		
		vector<int> a[N+1];
		int D[N+1][N+1];
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				cin>>D[i][j];
				if(D[i][j]!=-1) a[i].push_back(j);
			}
		}
		
		double d[N+1];
		bool check[N+1][N+1][N+1];
		
		cout<<"Case #"<<tc<<": ";
		while(Q--) {
			int u,v;
			cin>>u>>v;

			fill(d, d+N+1, INF);
			memset(check, false, sizeof(check));
			
			priority_queue<tuple<double,int,int,int,int>> q;
			q.push({0,u, 0, 0, 0});
			d[u]=0;

			while(!q.empty()) {
				double cost=-get<0>(q.top());
				int x=get<1>(q.top());
				int dist=get<2>(q.top());
				int speed=get<3>(q.top());
				int horse=get<4>(q.top());
				q.pop();
				
				if(x==v) {
					cout<<fixed<<setprecision(6)<<cost<<' ';
					break;
				}
				
				int next_dist=p[x].first;
				int next_speed=p[x].second;
				
				for(auto& y : a[x]) {
					double travel=D[x][y];
					
					if(dist-travel>=0 && check[x][y][horse]==false) {
						check[x][y][horse]=true;
						double next_cost=cost+((double)travel/speed);
						d[y]=next_cost;
						q.push({-d[y], y, dist-travel, speed, horse});
					}
					
					if(next_dist-travel>=0 && check[x][y][x]==false) {
						check[x][y][x]=true;
						double next_cost=cost+((double)travel/next_speed);
						d[y]=next_cost;
						q.push({-d[y], y, next_dist-travel, next_speed, x});
					}
				}
			}
		}
		
		cout<<'\n';
	}

	return 0;
}
