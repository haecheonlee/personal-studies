#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int N=10;

char a[N][N];
int d[N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
	int bx,by,lx,ly;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cin>>a[i][j];
			
			if(a[i][j]=='B') {
				bx=i;
				by=j;
			} else if(a[i][j]=='L') {
				lx=i;
				ly=j;
			}
		}
	}
	
	memset(d,-1,sizeof(d));
	queue<pi> q;
	q.push({bx,by});
	d[bx][by]=0;
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<N && 0<=ny && ny<N) {
				if(d[nx][ny]==-1 && a[nx][ny]!='R') {
					d[nx][ny]=d[x][y]+1;
					q.push({nx,ny});
				}
			}
		}
	}
	
	cout<<d[lx][ly]-1;
	
	return 0;
}
