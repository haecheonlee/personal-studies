#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=101;

char a[MAX][MAX];
int d[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
	int N,M;
	cin>>N>>M;
	
	int sx,sy,ex,ey;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin>>a[i][j];
			if(a[i][j]=='B') {
				sx=i;
				sy=j;
			} else if(a[i][j]=='C') {
				ex=i;
				ey=j;
			}
		}
	}
	
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
			
			if(0<=nx && nx<N && 0<=ny && ny<M) {
				if(a[nx][ny]!='*') {
					if(d[nx][ny]==-1) {
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
