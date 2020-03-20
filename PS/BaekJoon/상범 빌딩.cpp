#include <iostream>
#include <queue>

using namespace std;

int l,r,c;
char a[31][31][31];
int dist[31][31][31];
int dx[]={1,-1};
int dy[]={1,-1,0,0};
int dz[]={0,0,1,-1};

class Location {
public:
	int x;
	int y;
	int z;
	Location(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

void bfs(int x, int y, int z) {
	queue<Location> q;
	q.push({x,y,z});
	dist[x][y][z]=1;
	
	while(!q.empty()) {
		Location current=q.front();
		int x=current.x, y=current.y, z=current.z;
		q.pop();
		
		for(int k=0; k<2; k++) {
			int nx=x+dx[k];
			
			if(0<=nx && nx<l) {
				if(dist[nx][y][z]==0) {
					dist[nx][y][z]=dist[x][y][z]+1;
					q.push({nx,y,z});
				}
			}
		}
		
		for(int k=0; k<4; k++) {
			int ny=y+dy[k];
			int nz=z+dz[k];
			
			if(0<=ny && ny<r && 0<=nz && nz<c) {
				if(dist[x][ny][nz]==0) {
					dist[x][ny][nz]=dist[x][y][z]+1;
					q.push({x,ny,nz});
				}
			}
		}
	}
}

int main() {

	while(1) 
	{
		cin>>l>>r>>c;
		if(l==0 && r==0 && c==0) break;
		
		int start_x, start_y, start_z;
		int exit_x, exit_y, exit_z;
		for(int i=0; i<l; i++) {
			for(int j=0; j<r; j++) {
				for(int k=0; k<c; k++) {
					cin>>a[i][j][k];
					
					dist[i][j][k]=0;
					if(a[i][j][k]=='S') {
						start_x=i;
						start_y=j;
						start_z=k;
					} else if(a[i][j][k]=='#') {
						dist[i][j][k]=-1;
					} else if(a[i][j][k]=='E') {
						exit_x=i;
						exit_y=j;
						exit_z=k;
					}
				}
			}
		}
	
		bfs(start_x,start_y,start_z);
	
		if(dist[exit_x][exit_y][exit_z]>0) {
			cout<<"Escaped in "<<dist[exit_x][exit_y][exit_z]-1<<" minute(s).\n";
		}
		else {
			cout<<"Trapped!\n";
		}
	}
	return 0;
}

/*
INPUT:
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0

OUTPUT:
Escaped in 11 minute(s).
Trapped!
*/
