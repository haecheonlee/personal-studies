#include <iostream>
#include <vector>

using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int go(vector<string> &board, vector<bool> &check, int x, int y) {
	int ans=0;
	for(int k=0; k<=4; k++) {
		int nx=x+dx[k];
		int ny=y+dy[k];
		if(nx>=0 && nx<board.size() && ny>=0 && ny<board[0].size()) {
			if(check[board[nx][ny]-'A']==false) {
				check[board[nx][ny]-'A']=true;
				int next=go(board,check,nx,ny);
				if(ans<next) ans=next;
				check[board[nx][ny]-'A']=false;
			}
		}
	}
	
	return ans+1;
}

int main() {
	int n,m;
	cin>>n>>m;
	vector<string> board(n);
	for(int i=0; i<n; i++) cin>>board[i];
	
	vector<bool> check(26);
	check[board[0][0]-'A']=true;
	cout<<go(board,check,0,0);
	
	return 0;
}

/*
boj.kr/1987

INPUT:
2 4
CAAB
ADCB

OUTPUT:
3
*/
