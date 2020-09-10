#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=51;

char a[MAX][MAX];
bool check[MAX][MAX];	// passing by garbage
pi d[MAX][MAX];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) cin>>a[i][j];
	}

	int sx, sy, fx, fy;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(a[i][j]=='S') {
				sx=i;
				sy=j;
			} else if(a[i][j]=='F') {
				fx=i;
				fy=j;
			} else if(a[i][j]=='g') {
				for(int k=0; k<4; k++) {
					int nx=i+dx[k];
					int ny=j+dy[k];
					
					if(0<=nx && nx<N && 0<=ny && ny<M) {
						if(a[nx][ny]=='S' || a[nx][ny]=='F') continue;
						check[nx][ny]=true;
					}
				}
			}
		}
	}
	
	memset(d, -1, sizeof(d));
	priority_queue<pair<pi,pi>> q;	// { { garbage, next to grabage } , { pos_x, pos_y } }
	q.push({{0,0}, {sx,sy}});
	d[sx][sy]=make_pair(0,0);
	
	while(!q.empty()) {
		int garbage = -q.top().first.first;
		int next_to_garbage = -q.top().first.second;
		
		int x = q.top().second.first;
		int y = q.top().second.second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<N && 0<=ny && ny<M) {
				int g1=garbage;
				int g2=next_to_garbage;
				
				if(a[nx][ny]=='g') g1++;
				else if(check[nx][ny]==true) g2++;
				
				if(d[nx][ny]==make_pair(-1,-1)) {
					d[nx][ny]=make_pair(g1,g2);
					q.push({{-g1,-g2}, {nx,ny}});
				}
			}
		}
	}
	
	cout<<d[fx][fy].first<<' '<<d[fx][fy].second;
	
	return 0;
}
