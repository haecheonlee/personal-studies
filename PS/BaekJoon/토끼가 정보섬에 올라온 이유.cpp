#include <iostream>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e3+1;

int N,M;
char a[MAX][MAX];
int d[MAX][MAX];
int dx[]={-1,0,1};
int dy[]={1,1,1};

bool is_in_range(int x, int y) {
	return (0<=x && x<N && 0<=y && y<M);
}

int main() {
	cin>>N>>M;
	
	int sx,sy;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin>>a[i][j];
		
			if(a[i][j]=='R') {
				sx=i;
				sy=j;
			}
		}
	}
	
	memset(d, -1, sizeof(d));
	d[sx][sy]=0;
	
	for(int k=0; k<3; k++) {
		int nx=sx+dx[k];
		int ny=sy+dy[k];
		
		if(is_in_range(nx,ny)) {
			if(a[nx][ny]=='#') continue;
			else if(a[nx][ny]=='C') d[nx][ny]=d[sx][sy]+1;
			else d[nx][ny]=d[sx][sy];
		}
	}
	
	for(int y=1; y<M; y++) {
		for(int x=0; x<N; x++) {
			if(d[x][y]==-1) continue;
			else {
				for(int k=0; k<3; k++) {
					int nx=dx[k]+x;
					int ny=dy[k]+y;
					
					if(is_in_range(nx,ny)) {
						if(a[nx][ny]=='#') continue;
						else if(a[nx][ny]=='C') d[nx][ny]=max(d[nx][ny], d[x][y]+1);
						else d[nx][ny]=max(d[nx][ny], d[x][y]);
					}
				}
			}
		}
	}
	
	int ans=-1;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(a[i][j]=='O') ans=max(ans, d[i][j]);
		}
	}
	cout<<ans;

	return 0;
}
