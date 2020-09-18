#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int N=12;
const int M=6;

char a[N][M];
int d[N][M];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void destroy(vector<pi>& pos) {
	for(auto& p : pos) a[p.first][p.second]='.';
}

bool bfs(int sx, int sy) {
	const char color=a[sx][sy];
	vector<pi> pos;
	pos.push_back({sx,sy});
	
	queue<pi> q;
	q.push({sx,sy});
	d[sx][sy]=1;

	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=dx[k]+x;
			int ny=dy[k]+y;
			
			if(0<=nx && nx<N && 0<=ny && ny<M) {
				if(d[nx][ny]==-1 && a[nx][ny]==color) {
					pos.push_back({nx,ny});
					d[nx][ny]=d[x][y]+1;
					q.push({nx,ny});
				}
			}
		}
	}
	
	if(pos.size()>=4) destroy(pos);
	return pos.size()>=4;
}

void move() {
	for(int j=0; j<M; j++) {
		for(int i=N-1; i>0; i--) {
			if(a[i][j]=='.') {
				int x;
				for(x=i-1; x>0; x--) if(a[x][j]!='.') break;
				if(a[x][j]!='.') swap(a[x][j], a[i][j]);
			}
		}
	}
}

int main() {
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) cin>>a[i][j];
	}
	
	// from bottom to left
	int ans=0;
	while(1) {
		memset(d, -1, sizeof(d));
		
		bool is_destroyed=false;
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(a[i][j]!='.' && d[i][j]==-1) {
					if(bfs(i,j)) is_destroyed=true;
				}
			}
		}
		
		if(is_destroyed==false) break;
		else move();	
		
		ans++;
	}
	
	cout<<ans;

	return 0;
}
