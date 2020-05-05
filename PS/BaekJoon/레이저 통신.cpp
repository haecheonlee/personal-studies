#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

char a[101][101];
int d[101][101];
vector<pair<int,int>> list;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {
	int n,m;
	cin>>m>>n;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin>>a[i][j];
			
			if(a[i][j]=='C') list.push_back(make_pair(i,j));
			d[i][j]=-1;
		}
	}

	int sx,sy;
	tie(sx,sy)=list[0];

	queue<pair<int,int>> q;
	q.push(make_pair(sx,sy));
	d[sx][sy]=0;
	
	while(!q.empty()) {
		int x,y;
		tie(x,y)=q.front();
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=dx[k]+x;
			int ny=dy[k]+y;
			
			while(0<=nx && nx<n && 0<=ny && ny<m) {
				if(a[nx][ny]=='*') break;
				if(d[nx][ny]==-1) {
					d[nx][ny]=d[x][y]+1;
					q.push(make_pair(nx,ny));
				}
				nx+=dx[k];
				ny+=dy[k];
			}
		}
	}
	
	cout<<d[list[1].first][list[1].second]-1;
	
	return 0;
}

/*
INPUT:
7 8
.......
......C
......*
*****.*
....*..
....*..
.C..*..
.......

OUTPUT:
3
*/
