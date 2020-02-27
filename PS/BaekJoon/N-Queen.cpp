#include <iostream>
#include <vector>

using namespace std;

bool a[15][15];
int n;
bool check_col[15];
bool check_dig[40];
bool check_dig2[40];

bool check(int row, int col) {
	if(check_col[col]) return false;
	if(check_dig[row+col]) return false;
	if(check_dig2[row-col+n]) return false;
	
	return true;
}

int calc(int row) {
	if(row==n) return 1;
	
	int cnt=0;
	for(int col=0; col<n; col++) {
		if(check(row,col)) {
			check_dig[row+col]=true;
			check_dig2[row-col+n]=true;
			check_col[col]=true;
			a[row][col]=true;
			cnt+=calc(row+1);
			check_dig[row+col]=false;
			check_dig2[row-col+n]=false;
			check_col[col]=false;
			a[row][col]=false;
		}
	}
	return cnt;
}

int main() {
	cin>>n;
	cout<<calc(0);
 
	return 0;
}

/*
boj.kr/9663

INPUT:
8

OUTPUT:
92
*/
