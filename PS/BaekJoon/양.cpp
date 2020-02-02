#include <iostream>
#include <queue>

using namespace std;

char area[250][250];
bool check[250][250];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int r,c;

pair<int,int> bfs(int x, int y) {
	queue<pair<int,int>> q;
	q.push({x,y});
	check[x][y]=true;
	
	int o=0,v=0;
	
	while(!q.empty()) {
		int current_x=q.front().first;
		int current_y=q.front().second;
		
		if(area[current_x][current_y]=='v') v++;
		if(area[current_x][current_y]=='o') o++;
		q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=current_x+dx[k];
			int ny=current_y+dy[k];
			
			if(0<=nx && nx<r && 0<=ny && ny<c) {
				if(area[nx][ny]!='#' && check[nx][ny]==false) {
					check[nx][ny]=true;
					q.push({nx,ny});
				}
			}
		}
	}
	
	return make_pair(o,v);
}

int main() {
	cin>>r>>c;
	int sheep=0, wolf=0;
	
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cin>>area[i][j];
			if(area[i][j]=='#') check[i][j]=true;
		}
	}

	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(area[i][j]!='#' && check[i][j]==false) {
				pair<int,int> result=bfs(i,j);
				int s=result.first;
				int w=result.second;
				
				if(s>w) sheep+=s;
				else if(s<=w) wolf+=w;
			}
		}
	}
	
	cout<<sheep<<" "<<wolf;
	
	return 0;
}

/*
boj.kr/3184

INPUT:
9 12
.###.#####..
#.oo#...#v#.
#..o#.#.#.#.
#..##o#...#.
#.#v#o###.#.
#..#v#....#.
#...v#v####.
.####.#vv.o#
.......####.

OUTPUT:
3 5
*/
