#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=501;

int N,M,A,B,K;
int a[MAX][MAX];
int d[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

bool possible(int x, int y) {
	if(x+(A-1)<=0 || x+(A-1)>N || y+(B-1)<=0 || y+(B-1)>M) return false;
	
	for(int i=x; i<x+A; i++) {
		for(int j=y; j<y+B; j++) {
			if(a[i][j]==-1) return false;
		}
	}
	
	return true;
}

int main() {
	cin>>N>>M>>A>>B>>K;
	
	for(int i=0; i<K; i++) {
		int x,y;
		cin>>x>>y;
		
		a[x][y]=-1;
	}

	int sx,sy,ex,ey;
	cin>>sx>>sy>>ex>>ey;
	
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
			
			if(1<=nx && nx<=N && 1<=ny && ny<=M) {
				if(d[nx][ny]==-1 || d[nx][ny]>d[x][y]+1) {
					if(possible(nx,ny)) {
						d[nx][ny]=d[x][y]+1;
						q.push({nx,ny});
					}
				}
			}
		}
	}
	
	cout<<d[ex][ey];	

	return 0;
}
