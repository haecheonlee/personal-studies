#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

char a[1001][1001];
int d[1001][1001];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
	// initialization
	memset(d,-1,sizeof(d));

	int N,M;
	cin>>N>>M;
	
	pi pj;	// initial position of J
	vector<pi> sf;	// initial position of every fire	
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin>>a[i][j];
			
			if(a[i][j]=='J') {
				a[i][j]='.';
				pj.first=i;
				pj.second=j;
			} else if(a[i][j]=='F') {
				d[i][j]=-2;
				sf.push_back(make_pair(i,j));
			}
		}
	}
	
	queue<pi> q;	// stores J's position	
	q.push(pj);
	d[pj.first][pj.second]=0;

	queue<pi> fire_queue;	// stores all fire's position
	for(auto p : sf) fire_queue.push(p);
	
	while(!q.empty()) {
		queue<pi> q2;
		
		while(!q.empty()) {
			int x=q.front().first;
			int y=q.front().second;
			q.pop();
			if(d[x][y]==-2) continue;		// covered by fire later on
			
			for(int k=0; k<4; k++) {
				int nx=dx[k]+x;
				int ny=dy[k]+y;
				
				// escaped!
				if(nx>=N || ny>=M || nx<0 || ny<0) {
					cout<<d[x][y]+1;
					return 0;
				}
				
				if(0<=nx && nx<N && 0<=ny && ny<M) {
					if(d[nx][ny]==-1 && a[nx][ny]=='.') {
						d[nx][ny]=d[x][y]+1;
						q2.push(make_pair(nx,ny));
					}
				}
			}
		}
		
		queue<pi> fire_queue2;
		while(!fire_queue.empty()) {
			int x=fire_queue.front().first;
			int y=fire_queue.front().second;
			fire_queue.pop();
			
			for(int k=0; k<4; k++) {
				int nx=x+dx[k];
				int ny=y+dy[k];
				
				if(0<=nx && nx<N && 0<=ny && ny<M) {
					if(a[nx][ny]=='.' && d[nx][ny]!=-2) {
						d[nx][ny]=-2;
						fire_queue2.push(make_pair(nx,ny));
					}
				}
			}
		}
	
		q=q2;
		fire_queue=fire_queue2;
	}
	
	cout<<"IMPOSSIBLE";
	
	return 0;
}
