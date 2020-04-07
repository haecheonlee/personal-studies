#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
#include <cstring>

using namespace std;

typedef pair<int,int> pi;

int n,m;
int a[51][51];
int ans=-1;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
vector<pi> list;
vector<int> v;

void bfs() {
	int dist[51][51];
	memset(dist,-1,sizeof(dist));
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(a[i][j]==1) dist[i][j]=-2;
		}
	}
	
	deque<pi> dq;
	for(int i=0; i<v.size(); i++) {
		int x=list[v[i]].first;
		int y=list[v[i]].second;
		
		dq.push_front(make_pair(x,y));
		dist[x][y]=0;
	}
	
	while(!dq.empty()) {
		int x,y;
		tie(x,y)=dq.front();
		dq.pop_front();
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<n && 0<=ny && ny<n) {
				if(a[nx][ny]==1) continue;
				if(dist[nx][ny]==-1) {
					if(a[nx][ny]==2 || a[nx][ny]==0) {
						dist[nx][ny]=dist[x][y]+1;
						dq.push_back(make_pair(nx,ny));
					}
				}
			}
		}
	}
	
	int mx=-1;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(a[i][j]==0) {
				if(dist[i][j]==-1) return;
				mx=max(mx,dist[i][j]);
			}
		}
	}
	if(mx==-1) mx=0;
	if(ans==-1 || ans>mx) ans=mx;
}

void go(int index) {
	if(index==list.size()) {
		if(v.size()!=m) return;
		bfs();
		return;
	}
	
	v.push_back(index);
	go(index+1);
	v.pop_back();
	go(index+1);
}

int main() {
	cin>>n>>m;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin>>a[i][j];
			if(a[i][j]==2) list.push_back({i,j});
		}
	}
	
	go(0);
	cout<<ans;
	
	return 0;
}

/*
INPUT:
7 5
2 0 2 0 1 1 0
0 0 1 0 1 2 0
0 1 1 2 1 0 0
2 1 0 0 0 0 2
0 0 0 2 0 1 1
0 1 0 0 0 0 0
2 1 0 0 2 0 2

OUTPUT:
3
*/
