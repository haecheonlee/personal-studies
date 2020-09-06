#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

int R,C;
char a[101][101];
bool check[101][101];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void bfs(int sx, int sy) {
	queue<pi> q;
	q.push({sx, sy});
	check[sx][sy]=true;
	
	while(!q.empty()) {
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<R && 0<=ny && ny<C) {
				if(check[nx][ny]==false && a[nx][ny]=='1') {
					check[nx][ny]=true;
					q.push({nx,ny});
				}
			}
		}
	}
}

int main() {
	int T;
	cin>>T;
	
	for(int tc=1; tc<=T; tc++) {
		cin>>R>>C;
	
		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++) cin>>a[i][j];
		}
		
		int N;
		cin>>N;
		
		cout<<"Case #"<<tc<<":\n";
		while(N--) {
			char q;
			cin>>q;
			
			if(q=='Q') {
				memset(check, false, sizeof(check));

				int ans=0;
				for(int i=0; i<R; i++) {
					for(int j=0; j<C; j++) {
						if(a[i][j]=='1' && check[i][j]==false) {
							ans++;
							bfs(i,j);
						}
					}
				}
				cout<<ans<<'\n';
			} else {
				int x,y;
				char z;
				cin>>x>>y>>z;
				
				a[x][y]=z;
			}
		}
	}

	return 0;
}
