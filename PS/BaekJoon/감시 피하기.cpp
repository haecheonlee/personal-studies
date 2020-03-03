#include <iostream>
#include <vector>

using namespace std;

int n;
char a[6][6];
vector<pair<int,int>> p_t;
vector<pair<int,int>> p_x;
int list[3];
bool check[40];

bool validate() {
	for(int i=0; i<p_t.size(); i++) {
		int current_x=p_t[i].first;
		int current_y=p_t[i].second;
		
		// up
		for(int x=current_x-1; x>=0; x--) {
			if(a[x][current_y]=='X') continue;
			if(a[x][current_y]=='T' || a[x][current_y]=='O') break;
			if(a[x][current_y]=='S') return false;
		}
		
		// right
		for(int y=current_y+1; y<n; y++) {
			if(a[current_x][y]=='X') continue;
			if(a[current_x][y]=='T' || a[current_x][y]=='O') break;
			if(a[current_x][y]=='S') return false;
		}
		
		// down
		for(int x=current_x+1; x<n; x++) {
			if(a[x][current_y]=='X') continue;
			if(a[x][current_y]=='T' || a[x][current_y]=='O') break;
			if(a[x][current_y]=='S') return false;
		}

		// left
		for(int y=current_y-1; y>=0; y--) {
			if(a[current_x][y]=='X') continue;
			if(a[current_x][y]=='T' || a[current_x][y]=='O') break;
			if(a[current_x][y]=='S') return false;
		}
	}
	
	return true;
}

bool go(int index, int start) {
	if(index==3) {
		for(int i=0; i<index; i++) a[p_x[list[i]].first][p_x[list[i]].second]='O';
		bool result=validate();
		for(int i=0; i<index; i++) a[p_x[list[i]].first][p_x[list[i]].second]='X';
	
		return result;
	}
	
	for(int i=start; i<p_x.size(); i++) {
		if(check[i]) continue;
		check[i]=true;
		list[index]=i;
		bool result=go(index+1,i+1);
		if(result) return true;	
		check[i]=false;
	}
	
	return false;
}

int main() {
	cin>>n;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) { 
			cin>>a[i][j];
			
			if(a[i][j]=='X') p_x.push_back({i,j});
			else if(a[i][j]=='T') p_t.push_back({i,j});
		}
	}

	if(go(0,0)) cout<<"YES";
	else cout<<"NO";

	return 0;
}

/*
boj.kr/18248

INPUT:
5
X S X X T
T X S X X
X X X X X
X T X X X
X X T X X

OUTPUT:
YES
*/
