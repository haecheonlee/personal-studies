#include <iostream>

using namespace std;
using pi=pair<int,int>;

int board[9][9];	// [1][1] to [8][8]
pi moves[8]={{0,1},{0,-1},{-1,0},{1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int getIndex(string order) {
	if(order=="R") return 0;
	if(order=="L") return 1;
	if(order=="B") return 2;
	if(order=="T") return 3;
	if(order=="RT") return 4;
	if(order=="LT") return 5;
	if(order=="RB") return 6;
	if(order=="LB") return 7;
}

void setInitialPosition(string position, int &x, int &y) {
	x=(position[1]-'1')+1;
	y=(position[0]-'A')+1;
}

bool isInside(int nx, int ny) {
	if(1<=nx && nx<=8 && 1<=ny && ny<=8) return true;
	return false;
}

bool isAlreadyCovered(int nx, int ny, int x, int y) {
	if(nx==x && ny==y) return true;
	return false;
}

void print(int x, int y) {
	char R=(y-1)+'A';
	cout<<R<<x<<'\n';
}

int main() {
	string p1,p2;
	int N,x1,y1,x2,y2;;
	cin>>p1>>p2>>N;
	
	setInitialPosition(p1, x1, y1);
	setInitialPosition(p2, x2, y2);
	
	for(int i=0; i<N; i++) {
		string order;
		cin>>order;
		
		int index=getIndex(order);
		int p1_nx=x1+moves[index].first;
		int p1_ny=y1+moves[index].second;

		if(isInside(p1_nx,p1_ny)) {
			if(isAlreadyCovered(p1_nx, p1_ny, x2, y2)) {
				int p2_nx=x2+moves[index].first;
				int p2_ny=y2+moves[index].second;
				
				if(isInside(p2_nx, p2_ny)) {
					x1=p1_nx;
					y1=p1_ny;
					
					x2=p2_nx;
					y2=p2_ny;
				}
			} else {
				x1=p1_nx;
				y1=p1_ny;
			}
		}
	}
	
	print(x1,y1);
	print(x2,y2);
	
	return 0;
}
