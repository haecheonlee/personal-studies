#include <iostream>

using namespace std;

char board[101][101];
bool horizontal[101][101];
bool vertical[101][101];

int main() {
	int N;
	cin>>N;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) board[i][j]='.';
	}

	char move;
	int x=0, y=0;
	while(cin>>move) {
		int nx,ny;		
		if(move=='U') {
			nx=x-1;
			ny=y;
		} else if(move=='D') {
			nx=x+1;
			ny=y;
		} else if(move=='L') {
			nx=x;
			ny=y-1;
		} else if(move=='R') {
			nx=x;
			ny=y+1;
		}
		
		if(0<=nx && nx<N && 0<=ny && ny<N) {
			if(move=='U' || move=='D') {
				horizontal[x][y]=true;	
				horizontal[nx][ny]=true;	
			}
			
			if(move=='L' || move=='R') {
				vertical[x][y]=true;	
				vertical[nx][ny]=true;	
			}
			
			x=nx;
			y=ny;
		}
	}
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(horizontal[i][j] && vertical[i][j]) board[i][j]='+';
			else if(horizontal[i][j]) board[i][j]='|';
			else if(vertical[i][j]) board[i][j]='-';
			cout<<board[i][j];
		}
		cout<<endl;
	}

	return 0;
}
