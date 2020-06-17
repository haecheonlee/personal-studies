#include <iostream>
#define n 9

using namespace std;

int a[n][n];

bool isValidRow(bool check[n][n]) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			int x=a[i][j]-1;
			if(check[i][x]) return false;
			check[i][x]=true;
		}
	}
	
	return true;
}

bool isValidCol(bool check[n][n]) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			int x=a[j][i]-1;
			if(check[x][i]) return false;
			check[x][i]=true;
		}
	}
	
	return true;
}

bool isValidArea(bool check[n][n]) {
	for(int i=0; i<n; i++) {
		int row=(i/3)*3;
		int col=(i%3)*3;
		for(int x=row; x<row+3; x++) {
			for(int y=col; y<col+3; y++) {
				int z=a[x][y]-1;
				if(check[i][z]) return false;
				check[i][z]=true;
			}	
		}
	}
	
	return true;
}

int main() {
	int t;
	cin>>t;
	
	for(int i=1; i<=t; i++) {
		bool check1[n][n] {false};
		bool check2[n][n] {false};
		bool check3[n][n] {false};
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) cin>>a[i][j];
		}
		
		if(isValidRow(check1) && isValidCol(check2) && isValidArea(check3)) {
			printf("Case %d: CORRECT\n", i);
		} else {
			printf("Case %d: INCORRECT\n", i);
		}
	}

	return 0;
}
