#include <iostream>

using namespace std;

int a[19][19];
bool check[19][19][4] {false}; // 0-down 1-right 2-right diagonal 3-left diagonal
int result_x, result_y;

bool solve(int x,int y, int color) {
	// down
	int cnt=0;
	if(check[x][y][0]==false) {
		while((x+cnt)<19 && color==a[x+cnt][y]) {
			check[x+cnt][y][0]=true;
			cnt++;
		}
		
		if(cnt==5) {
			result_x=x+1;
			result_y=y+1;
			
			return true;
		}
	}
	
	// right
	if(check[x][y][1]==false) {
		cnt=0;
		while((y+cnt)<19 && color==a[x][y+cnt]) {
			check[x][y+cnt][1]=true;
			cnt++;
		}
		
		if(cnt==5) { 
			result_x=x+1;
			result_y=y+1;
			
			return true;
		}
	}
	
	// right diagonal
	if(check[x][y][2]==false) {
		cnt=0;
		while(((x+cnt)<19 && (y+cnt)<19) && color==a[x+cnt][y+cnt]) {
			check[x+cnt][y+cnt][2]=true;
			cnt++;
		}
		
		if(cnt==5) {
			result_x=x+1;
			result_y=y+1;
			
			return true;
		}
	}
	
	if(check[x][y][3]==false) {
		cnt=0;
		while(((x+cnt)<19 && (y-cnt)>=0) && color==a[x+cnt][y-cnt]) {
			check[x+cnt][y-cnt][3]=true;
			cnt++;
		}
		
		if(cnt==5) { 
			result_x=x+1+4;
			result_y=y+1-4;
	
			return true;
		}
	}

	return false;
}

int main() {
	for(int i=0; i<19; i++) {
		for(int j=0; j<19; j++) cin>>a[i][j];
	}
	
	for(int i=0; i<19; i++) {
		for(int j=0; j<19; j++) {
			if(a[i][j]==1 || a[i][j]==2) {
				if(solve(i,j,a[i][j])) {
					cout<<a[i][j]<<'\n';
					cout<<result_x<<" "<<result_y;
					return 0;
				}			
			}
		}
	}
	
	cout<<0;

	return 0;
}

/*
INPUT:
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 1 2 0 0 2 2 2 1 0 0 0 0 0 0 0 0 0 0
0 0 1 2 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0
0 0 0 1 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 2 2 0 0 0 0 0 0 0 0 0 0 0 0
0 0 1 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 2 1 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

OUTPUT:
1
3 2
*/
