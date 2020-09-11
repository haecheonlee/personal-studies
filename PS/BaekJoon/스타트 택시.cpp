#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=21;

int N,M,F;
int a[MAX][MAX];
int d[MAX][MAX];
vector<pair<pi,pi>> p;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void bfs(int sx, int sy) {
	// bfs from the current position of driver
	memset(d, -1, sizeof(d));
	
	queue<pi> q;
	q.push({sx,sy});
	d[sx][sy]=0;
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(1<=nx && nx<=N && 1<=ny && ny<=N) {
				if(a[nx][ny]==0 && d[nx][ny]==-1) {
					d[nx][ny]=d[x][y]+1;
					q.push({nx,ny});
				}
			}
		}
	}
}

int main() {
	cin>>N>>M>>F;
	
	// initialization
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) cin>>a[i][j];
	}

	// initial position of driver
	int bx,by;
	cin>>bx>>by;

	// position of each passenger
	p.resize(M);
	for(int i=0; i<M; i++) {
		cin>>p[i].first.first>>p[i].first.second;
		cin>>p[i].second.first>>p[i].second.second;
	}
	sort(p.begin(), p.end());	// to choose the lower [row], when multiple min distance found
	
	while(p.size()) {
		bfs(bx,by);
		
		int selected=-1;
		int passenger=1e9;	// driver to passenger
		int psx, psy, pex, pey;	// passenger's initial position & destination
		
		// find the min_distance from driver to passenger
		for(int i=0; i<p.size(); i++) {
			int sx=p[i].first.first;
			int sy=p[i].first.second;
			int ex=p[i].second.first;
			int ey=p[i].second.second;
			
			if(passenger>d[sx][sy]) {
				selected=i;
				psx=sx, psy=sy;
				pex=ex, pey=ey;
				passenger=d[sx][sy];
			}
		}

		// passenger to destination
		bfs(psx,psy);
		int destination = d[pex][pey];
		
		// not able to reach the position
		if(passenger==-1 || destination==-1) {
			cout<<-1;
			return 0;
		} else {
			int required = passenger + destination;	// total requierd fuel
			// is possible to arrive destination with the current fuel?
			if(F>=required) {
				F=(F-required) + (destination * 2);
				bx=pex, by=pey;					// update the driver's position
				p.erase(p.begin() + selected);	// remove the passenger from list
			} else {
				cout<<-1;
				return 0;
			}
		}
	}

	cout<<F;

	return 0;
}
