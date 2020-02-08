#include <iostream>
#include <queue>

using namespace std;

queue<pair<int,int>> water_q;
queue<pair<int,int>> water_next_q;
queue<pair<int,int>> mole_q;
queue<pair<int,int>> mole_next_q;

char area[50][50];
int dist[50][50];
int r,c;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

void bfs_water() {
	while(!water_q.empty()) {
		int current_x=water_q.front().first;
		int current_y=water_q.front().second;
		water_q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=current_x+dx[k];
			int ny=current_y+dy[k];
			
			if(0<=nx && nx<r && 0<=ny && ny<c) {
				if(area[nx][ny]!='*' && area[nx][ny]!='D' && area[nx][ny]!='X') {
					area[nx][ny]='*';
					water_next_q.push({nx,ny});
				}
			}
		}
	}
}

void bfs_mole() {
	while(!mole_q.empty()) {
		int current_x=mole_q.front().first;
		int current_y=mole_q.front().second;
		mole_q.pop();
		
		for(int k=0; k<4; k++) {
			int nx=current_x+dx[k];
			int ny=current_y+dy[k];
			
			if(0<=nx && nx<r && 0<=ny && ny<c) {
				if(area[nx][ny]=='.' || area[nx][ny]=='D') {
					mole_next_q.push({nx,ny});
					area[nx][ny]='S';
					dist[nx][ny]=dist[current_x][current_y]+1;
				}
			}
		}
	}
}

int main() {
	cin>>r>>c;
	
	int pos_x,pos_y;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cin>>area[i][j];
			
			if(area[i][j]=='*') water_q.push({i,j});
			else if(area[i][j]=='S') mole_q.push({i,j});
			else if(area[i][j]=='D') {
				pos_x=i;
				pos_y=j;
			}
		}
	}
	
	for(int i=0; i<r+c; i++) {
		while(!water_next_q.empty()) {
			water_q.push(water_next_q.front());
			water_next_q.pop();
		}
		
		while(!mole_next_q.empty()) {
			mole_q.push(mole_next_q.front());
			mole_next_q.pop();
		}
		
		bfs_water();
		bfs_mole();
		
		if(dist[pos_x][pos_y]!=0) {
			cout<<dist[pos_x][pos_y];
			return 0;
		}
	}
	
	cout<<"KAKTUS";

	return 0;
}

/*
boj.kr/3055

INPUT:
5 4
.D.*
....
..X.
S.*.
....

OUTPUT:
4
*/
