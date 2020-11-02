#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;

const int MAX = 1e3 + 1;
const ll INF = 1e15;

vector<int> a[MAX];
pli adj[MAX][MAX];
pli d[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int S,E,N;
	cin>>S>>E>>N;
	
	for(int i = 0; i < N; i++) {
		int c,p;
		cin>>c>>p;
		
		int city[p];
		for(int x = 0; x < p; x++) cin>>city[x];
		

		for(int x = 0; x < p; x++) {
			for(int y = x + 1; y < p; y++) {
				int u = city[x], v = city[y];
				int flights = y - x;

				if(adj[u][v].first == 0) {
					a[u].push_back(v);
					adj[u][v].first = c;
					adj[u][v].second = flights;
				} else {
					if(adj[u][v].first > c) {
						adj[u][v].first = c;
						adj[u][v].second = flights;
					} else if(adj[u][v].first == c && adj[u][v].second > flights ) {
						adj[u][v].second = flights;
					}
				}
			}
		}
	}
	
	fill(d, d + MAX, make_pair(INF, INF));
	priority_queue<pair<pli, int>> q;
	q.push({{0, 0}, S});
	d[S].first = d[S].second = 0;
	
	while(!q.empty()) {
		ll c = -q.top().first.first;
		int f = -q.top().first.second;
		int x = q.top().second;
		q.pop();
		
		if(d[x].first < c || (d[x].first == c && d[x].second < f)) continue;
		for(auto& y : a[x]) {
			ll nc = adj[x][y].first + c;
			ll nf = adj[x][y].second + f;
			
			if(d[y].first > nc) {
				d[y].first = nc; d[y].second = nf;
				q.push({{-nc, -nf}, y});
			} else if(d[y].first == nc) {
				if(d[y].second > nf) {
					d[y].second = nf;
					q.push({{-nc, -nf}, y});
				}
			}
		}
	}
	
	if(d[E].first == INF) cout<<"-1 -1";
	else cout<<d[E].first<<' '<<d[E].second<<'\n';
	
	return 0;
}
