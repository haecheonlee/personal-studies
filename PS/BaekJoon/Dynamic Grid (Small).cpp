#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

int R,C;
char a[100][100];
bool check[100][100];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void bfs(int sx, int sy) {
	queue<pi> q;
	q.push({sx,sy});
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
	
	for(int i=1; i<=T; i++) {
		cin>>R>>C;
		
		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++) {
				cin>>a[i][j];
			}
		}
		
		cout<<"Case #"<<i<<":\n";
		int N;
		cin>>N;
		
		while(N--) {
			char opr;
			cin>>opr;
			
			if(opr=='M') {
				int r,c;
				char o;
				cin>>r>>c>>o;
				
				a[r][c]=o;
			} else {
				memset(check,false,sizeof(check));
			
				int ans=0;
				for(int i=0; i<R; i++) {
					for(int j=0; j<C; j++) {
						if(a[i][j]=='1' && check[i][j]==false) {
							bfs(i,j);
							ans++;
						}
					}
				}
				cout<<ans<<'\n';
			}
		}
	}

	return 0;
}
