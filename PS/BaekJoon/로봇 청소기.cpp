#include <iostream>

using namespace std;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int getBackPosition(int current_direction) {
	switch(current_direction) {
		case 0:
			return 2;
		case 1:
			return 3;
		case 2:
			return 0;
		case 3:
			return 1;
	}
}

int rotate(int current_direction) {
	switch(current_direction) {
		case 0:
			return 3;
		case 1:
			return 0;
		case 2:
			return 1;
		case 3:
			return 2;
	}
}

int main() {
	int n,m,r,c,d;
	cin>>n>>m>>r>>c>>d;
	
	int area[n][m];
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) cin>>area[i][j];
	}

	int current_direction=d,next_direction=d;
	
	while(1) {
		area[r][c]=2;
		
		bool check=true;
		int start=4;
		while(start--) {
			next_direction=rotate(next_direction);

			if(area[r+dx[next_direction]][c+dy[next_direction]]==0) {
				r+=dx[next_direction];
				c+=dy[next_direction];
				
				area[r][c]=2;
				current_direction=next_direction;
				
				check=false;
				break;
			}
		}
		
		if(check) {
			int back_position=getBackPosition(current_direction);
			
			if(area[r+dx[back_position]][c+dy[back_position]]!=1) {
				r+=dx[back_position];
				c+=dy[back_position];
			} else {
				break;
			}
		}
	}

	int cnt=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(area[i][j]==2) cnt++;
		}
	}
	cout<<cnt;

	return 0;
}

/*
boj.kr/14503

INPUT:
11 10
7 4 0
1 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 1 1 1 1 0 1
1 0 0 1 1 0 0 0 0 1
1 0 1 1 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 1 0 1
1 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1

OUTPUT:
57
*/
