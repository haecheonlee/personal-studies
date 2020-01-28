#include <iostream>
#include <queue>

using namespace std;

int box[100][100][100];
int dist[100][100][100];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int dz[]={1,-1};
int m,n,h;

class Location {
public:
	int x;
	int y;
	int z;
	Location(int _z, int _y, int _x) : z(_z), y(_y), x(_x) {}
};

int main() {
	cin>>m>>n>>h;
	
	queue<Location> q;
	for(int i=0; i<h; i++) {
		for(int j=0; j<n; j++) {
			for(int x=0; x<m; x++) {
				cin>>box[i][j][x];
				dist[i][j][x]=-1;
				if(box[i][j][x]==1) {
					q.push({i,j,x});
					dist[i][j][x]=0;
				}
			}
		}
	}
	
	while(!q.empty()) {
		Location l = q.front();
		int z=l.z; int y=l.y; int x=l.x;
		q.pop();

		for(int k=0; k<2; k++) {
			int nz=z+dz[k];
			if(0<=nz && nz<h) {
				if(box[nz][y][x]==0 && dist[nz][y][x]==-1) {
					dist[nz][y][x]=dist[z][y][x]+1;
					q.push({nz,y,x});
				}
			}
		}
		
		for(int k=0; k<4; k++) {
			int ny=y+dy[k];
			int nx=x+dx[k];
			
			if(0<=nx && nx<m && 0<=ny && ny<n) {
				if(box[z][ny][nx]==0 && dist[z][ny][nx]==-1) {
					dist[z][ny][nx]=dist[z][y][x]+1;
					q.push({z,ny,nx});
				}
			}
		}
	}
	
	int result=0;
	for(int i=0; i<h; i++) {
		for(int j=0; j<n; j++) {
			for(int x=0; x<m; x++) {
				if(result<dist[i][j][x]) result=dist[i][j][x];
				if(box[i][j][x]==0 && dist[i][j][x]==-1) {
					cout<<-1;
					return 0;
				}
			}
		}
	}
	
	cout<<result;

	return 0;
}

/*
boj.kr/7569

INPUT:
5 3 2
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 1 0 0
0 0 0 0 0

OUTPUT:
4
*/
