#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

// direction => N: 0, E: 1, S: 2, W: 3
struct Robot {
	int x,y,d;
	Robot(int x, int y, int d) : x(x), y(y), d(d) {}
};

int A,B,N,M;
int board[101][101];
vector<Robot> robots;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

inline int getIndexOfDirection(string s) {
	if(s=="N") return 0;
	else if(s=="E") return 1;
	else if(s=="S") return 2;
	else if(s=="W") return 3;
}

int rotate(string s, int direction) {
	if(s=="L") {
		if(--direction<0) direction=3;
		return direction;
	} else {
		if(++direction>3) direction=0;
		return direction;
	}
}

inline bool isOutside(int nx, int ny) {
	if(1>nx || nx>B || 1>ny || ny>A) return true;
	return false;
}

inline bool isCovered(int nx, int ny) {
	if(board[nx][ny]!=-1) return true;
	return false;
}

int main() {
	// board => -1: no robot found, (i): ith robot currently stays in.
	memset(board,-1,sizeof(board));
	
	cin>>A>>B>>N>>M;
	
	for(int i=0; i<N; i++) {
		int x,y;
		string d;
		cin>>y>>x>>d;
		
		robots.push_back({x,y,getIndexOfDirection(d)});
		board[x][y]=i;
	}
	
	while(M--) {
		int index;
		string order;
		int count;
		
		cin>>index>>order>>count;
		index--;	// vector<Robot> robots starts from [0] to [N-1];
		
		while(count--) {
			if(order=="F") {
				// foward
				int x=robots[index].x;
				int y=robots[index].y;
				int d=robots[index].d;
				
				
				int nx=x+dx[d];
				int ny=y+dy[d];
				
				if(isOutside(nx,ny)) {
					printf("Robot %d crashes into the wall", index+1);
					return 0;
				}
				
				if(isCovered(nx,ny)) {
					printf("Robot %d crashes into robot %d", index+1, board[nx][ny]+1);
					return 0;
				}
				
				// update
				swap(board[x][y], board[nx][ny]);
				robots[index].x=nx;
				robots[index].y=ny;
			} else {
				// change direction
				robots[index].d=rotate(order, robots[index].d);
			}
		}
	}

	cout<<"OK";

	return 0;
}
