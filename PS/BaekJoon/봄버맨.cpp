#include <iostream>
#include <vector>

using namespace std;
using pi=pair<int,int>;

int R,C,N;

char board[201][201];
vector<pi> bomb;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void fill() {
	bomb.clear();
	
	for(int i=0; i<R; i++) {
		for(int j=0; j<C; j++) {
			if(board[i][j]=='O') bomb.push_back(make_pair(i,j));
			else board[i][j]='O';
		}
	}
}

void explode() {
	for(auto& p : bomb) {
		int x=p.first;
		int y=p.second;
		board[x][y]='.';
		
		for(int k=0; k<4; k++) {
			int nx=x+dx[k];
			int ny=y+dy[k];
			
			if(0<=nx && nx<R && 0<=ny && ny<C) board[nx][ny]='.';
		}
	}
}

void print() {
	for(int i=0; i<R; i++) {
		for(int j=0; j<C; j++) cout<<board[i][j];
		cout<<'\n';
	}
}

int main() {
	cin>>R>>C>>N;
	
	for(int i=0; i<R; i++) {
		for(int j=0; j<C; j++) {
			cin>>board[i][j];
		}
	}
	
	int t=2;
	while(t<=N) {
		if(t%2==0) fill();
		else explode();
		t++;
	}
	print();
	
	return 0;
}
