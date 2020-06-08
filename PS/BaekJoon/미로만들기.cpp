#include <iostream>
#include <cstring>
#include <deque>
#include <tuple>

using namespace std;

int dist[51][51];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

int main() {
	int n;
	cin>>n;

	memset(dist, -1, sizeof(dist));
	
	string a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	
	// start
	deque<pair<int,int>> q;
	q.push_back(make_pair(0,0));
	dist[0][0]=0;
	
	while(!q.empty()) {
		int x,y;
		tie(x,y)=q.front();
		q.pop_front();
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<n && 0<=ny && ny<n) {
				if(dist[nx][ny]!=-1) continue;
				
				if(a[nx][ny]=='1') {
					dist[nx][ny]=dist[x][y];
					q.push_front(make_pair(nx,ny));
				} else {
					dist[nx][ny]=dist[x][y]+1;
					q.push_back(make_pair(nx,ny));
				}
			}
		}
	}
	
	if(dist[n-1][n-1]==-1) cout<<0;
	else cout<<dist[n-1][n-1];

	return 0;
}
