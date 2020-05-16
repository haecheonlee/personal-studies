#include <iostream>
#include <tuple>

using namespace std;
using PI=pair<int,int>;

int n;
int a[17][17];
// 0 - horizontal, 1 - vertical, 2 - diagonal

bool isPossible(int x, int y) {
	if(0<=x && x<n && 0<=y && y<n) return true;
	else return false;
}

bool check(int x, int y, int direction) {
	if(direction==0) 
		return isPossible(x,y+1) && a[x][y+1]==0;
	else if(direction==1) 
		return isPossible(x+1,y) && a[x+1][y]==0;
	else if(direction==2) 
		return isPossible(x+1,y+1) && a[x][y+1]==0 && a[x+1][y]==0 && a[x+1][y+1]==0;
}

int solve(PI pos, int direction) {
	if(pos.first==n-1 && pos.second==n-1) return 1;
	int cnt=0;
	
	if(direction==0) {
		// to horizontal
		if(check(pos.first, pos.second, 0)) cnt+=solve(make_pair(pos.first, pos.second+1), 0);
		
		// to diagonal
		if(check(pos.first, pos.second, 2)) cnt+=solve(make_pair(pos.first+1, pos.second+1), 2);
	} else if(direction==1) {
		// to vertical
		if(check(pos.first, pos.second, 1)) cnt+=solve(make_pair(pos.first+1, pos.second), 1);
		
		// to diagonal
		if(check(pos.first, pos.second, 2)) cnt+=solve(make_pair(pos.first+1, pos.second+1), 2);
	} else if(direction==2) {
		// to horizontal
		if(check(pos.first, pos.second, 0)) cnt+=solve(make_pair(pos.first, pos.second+1), 0);

		// to vertical
		if(check(pos.first, pos.second, 1)) cnt+=solve(make_pair(pos.first+1, pos.second), 1);
		
		// to diagonal
		if(check(pos.first, pos.second, 2)) cnt+=solve(make_pair(pos.first+1, pos.second+1), 2);
	}
	
	return cnt;
}

int main() {
	cin>>n;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) cin>>a[i][j];	
	}

	cout<<solve(make_pair(0,1), 0);

	return 0;
}
