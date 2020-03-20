#include <iostream>
#include <queue>

using namespace std;
typedef pair<int,int> PI;

int n,w,h,ans;
char building[1002][1002];
int dist[1002][1002];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
queue<PI> fire;
queue<PI> person;

void bfs() {
	while(!person.empty()) {
		queue<PI> next_person=person;
		person=queue<PI>();
		while(!next_person.empty()) {
			int x=next_person.front().first;
			int y=next_person.front().second;
			next_person.pop();
			
			if(dist[x][y]==-2) continue;
			for(int k=0; k<4; k++) {
				int nx=x+dx[k];
				int ny=y+dy[k];
				
				if(0<=nx && nx<h && 0<=ny && ny<w) {
					if(dist[nx][ny]==0) {
						dist[nx][ny]=dist[x][y]+1;
						person.push({nx,ny});
					}
				} else {
					ans=dist[x][y];
					return;
				}
			}
		}

		queue<PI> next_fire=fire;
		fire=queue<PI>();
		while(!next_fire.empty()) {
			int x=next_fire.front().first;
			int y=next_fire.front().second;
			next_fire.pop();
			
			for(int k=0; k<4; k++) {
				int nx=x+dx[k];
				int ny=y+dy[k];
				
				if(0<=nx && nx<h && 0<=ny && ny<w) {
					if(dist[nx][ny]>=0) {
						dist[nx][ny]=-2;
						fire.push({nx,ny});
					}
				}
			}
		}
	}
}

int main() {
	cin>>n;
	
	while(n--) {
		cin>>w>>h;
	
		person=queue<PI>();
		fire=queue<PI>();
		
		for(int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				cin>>building[i][j];
				
				dist[i][j]=0;
				if(building[i][j]=='#') {
					dist[i][j]=-1;
				} else if(building[i][j]=='*') {
					fire.push({i,j});
					dist[i][j]=-2;
				} else if(building[i][j]=='@') {
					person.push({i,j});
					dist[i][j]=1;
				}
			}
		}
		
		ans=-1;
		bfs();
		
		if(ans==-1) cout<<"IMPOSSIBLE\n";
		else cout<<ans<<'\n';
	}
	
	return 0;
}

/*
INPUT:
5
4 3
####
#*@.
####
7 6
###.###
#*#.#*#
#.....#
#.....#
#..@..#
#######
7 4
###.###
#....*#
#@....#
.######
5 5
.....
.***.
.*@*.
.***.
.....
3 3
###
#@#
###

OUTPUT:
2
5
IMPOSSIBLE
IMPOSSIBLE
IMPOSSIBLE
*/
