#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;
using pi=pair<int,int>;

const int INF=1e9;
const int MAX=1e4+1;

vector<pi> a[4100];
int d[4100];
vector<pi> pos;
bool check[MAX];

int get_dist(pi p1, pi p2) {
	double x=p1.first-p2.first;
	double y=p1.second-p2.second;
	
	return (int)sqrt((x*x)+(y*y));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// find prime number
	for(int i=2; i<MAX; i++) {
		if(check[i]==false) {
			for(int j=i+i; j<MAX; j+=i) check[j]=true;
		}
	}
	
	// initialization
	int sx,sy,ex,ey;
	cin>>sx>>sy>>ex>>ey;
	
	int N;
	cin>>N;
	
	pos.push_back({sx,sy});
	for(int i=0; i<N; i++) {
		int x,y;
		cin>>x>>y;
		
		pos.push_back({x,y});
	}
	pos.push_back({ex,ey});
	
	for(int i=0; i<pos.size(); i++) {
		for(int j=0; j<pos.size(); j++) {
			int weight=get_dist(pos[i],pos[j]);
			if(check[weight]==false) {
				// if dist is prime
				a[i].push_back({j,weight});
				a[j].push_back({i,weight});
			}
		}
	}
	
	// dijkstra
	memset(d,0x3f,sizeof(d));

	priority_queue<pi> q;
	q.push({0,0});
	d[0]=0;
	while(!q.empty()) {
		int cost=-q.top().first;
		int x=q.top().second;
		q.pop();
		
		if(d[x]<cost) continue;
		for(auto& next : a[x]) {
			int y=next.first;
			int weight=next.second+cost;
			
			if(d[y]>weight) {
				d[y]=weight;
				q.push({-weight,y});
			}
		}
	}
	
	cout<<((d[N+1]==0x3f3f3f3f) ? -1 : d[N+1]);

	return 0;
}
