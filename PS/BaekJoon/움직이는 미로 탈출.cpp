#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

bool check[8][8][9];
int dx[]={0,0,1,-1,1,-1,1,-1,0};
int dy[]={1,-1,0,0,1,1,-1,-1,0};

int main() {
	int n=8;
	vector<string> a(n);
	for(int i=0; i<n; i++) cin>>a[i];
	
	queue<tuple<int,int,int>> q;
	check[7][0][0]=true;
	q.push(make_tuple(7,0,0));
	
	bool ans=false;
	while(!q.empty()) {
		int x, y, t;
		tie(x,y,t)=q.front(); q.pop();
		if(x==0 && y==7) ans=true;
		
		for(int k=0; k<9; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			int nt=min(t+1,8);
			
			if(0<=nx && nx<n && 0<=ny && ny<n) {
				if(nx-t>=0 && a[nx-t][ny]=='#') continue;
				if(nx-t-1>=0 && a[nx-t-1][ny]=='#') continue;
				if(check[nx][ny][nt]==false) {
					check[nx][ny][nt]=true;
					q.push(make_tuple(nx,ny,nt));
				}
			}
		}
	}
	
	cout<<(ans ? 1 : 0);
	
	return 0;
}

/*
INPUT:
........
........
........
........
........
.#######
#.......
........

OUTPUT:
1
*/
