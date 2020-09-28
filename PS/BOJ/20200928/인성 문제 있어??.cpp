#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e2+1;

int a[MAX][MAX];
int d[MAX][MAX];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N,M,O,F,sx,sy,ex,ey;
		cin>>N>>M>>O>>F>>sx>>sy>>ex>>ey;
		
		memset(a, 0, sizeof(a));
		memset(d, -1, sizeof(d));
		while(O--) {
			int X,Y,L;
			cin>>X>>Y>>L;
			a[X][Y]=L;
		}
		
		queue<pi> q;
		q.push({sx,sy});
		d[sx][sy]=F+1;
		
		while(!q.empty()) {
			int x=q.front().first;
			int y=q.front().second;
			q.pop();
			
			d[x][y]--;
			if(d[x][y]==0) continue;
			
			for(int k=0; k<4; k++) {
				int nx=x+dx[k];
				int ny=y+dy[k];
				
				if(1<=nx && nx<=N && 1<=ny && ny<=M) {
					if(a[x][y]<a[nx][ny]) {
						// jump required
						int energy=a[nx][ny]-a[x][y];
						if(d[x][y]>=energy) {
							if(d[nx][ny]==-1 || d[nx][ny]<d[x][y]) {
								d[nx][ny]=d[x][y];
								q.push({nx,ny});
							}
						}
					} else {
						if(d[nx][ny]==-1 || d[nx][ny]<d[x][y]) {
							d[nx][ny]=d[x][y];
							q.push({nx,ny});
						}
					}
				}
			}
		}
		
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=M; j++) cout<<d[i][j]<<' ';
			cout<<endl;
		}
		
		if(d[ex][ey]!=-1) cout<<"잘했어!!\n";
		else cout<<"인성 문제있어??\n";
	}

	return 0;
}
