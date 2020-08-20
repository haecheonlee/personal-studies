#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int INF=1e9;

vector<pi> edge1[20];
vector<pi> edge2[20];
int adj[20][20][2];
int d[20][2];

void dijkstra(vector<pi> a[20], int type) {
	priority_queue<pair<int,pi>> q;	// cost, {from, to}
	d[0][0]=d[0][1]=0;
	q.push({0,{0,0}});
	
	while(!q.empty()) {
		int cost=-q.top().first;
		int p=q.top().second.first;
		int x=q.top().second.second;
		q.pop();
		
		if(d[x][0]<cost) continue;
		for(auto& v : a[x]) {
			int y=v.first;
			int weight=cost+v.second;
			
			if(d[y][0]>weight) {
				d[y][0]=weight;
				d[y][1]=d[x][1]+adj[x][y][1-type];
				q.push({-weight,{x,y}});
			}
		}
	}
}

int main() {
	int N;
	cin>>N;
	
	// weight 2
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			char x;
			cin>>x;
			
			if(x!='.') {
				edge1[i].push_back({j,x-'0'});
				adj[i][j][0]=x-'0';
			} else {
				adj[i][j][0]=INF;
			}
		}
	}
	
	// weight 2
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			char x;
			cin>>x;
			
			if(x!='.') {
				edge2[i].push_back({j,x-'0'});
				adj[i][j][1]=x-'0';
			} else {
				adj[i][j][1]=INF;
			}
		}
	}

	// dijkstra for weight 1 
	memset(d,0x3f,sizeof(d));
	dijkstra(edge1,0);
	
	// not reached, then impossible
	if(d[1][0]==0x3F3F3F3F || d[1][1]==0x3F3F3F3F) {
		cout<<-1;
		return 0;
	}
	
	int w1=d[1][0]*d[1][1];
	
	// dijkstra for weight 2
	memset(d,0x3f,sizeof(d));
	dijkstra(edge2,1);
	
	int w2=d[1][0]*d[1][1];
	cout<<((w2>w1) ? w1 : w2);
	
	return 0;
}
