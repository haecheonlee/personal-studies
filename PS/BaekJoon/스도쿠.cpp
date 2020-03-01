#include <iostream>

using namespace std;

int a[10][10];
bool c[10][10];
bool c2[10][10];
bool c3[10][10];
int n=9;

int square(int x, int y) {
	return (x/3)*3+(y/3);
}

bool go(int z) {
	if(z==81) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				cout<<a[i][j]<<' ';
			}
			cout<<'\n';
		}
		return true;
	}
	
	int x=z/n;
	int y=z%n;
	if(a[x][y]!=0) {
		return go(z+1);
	} else {
		for(int i=1; i<=9; i++) {
			if(c[x][i]==0 && c2[y][i]==0 && c3[square(x,y)][i]==0) {
				c[x][i]=c2[y][i]=c3[square(x,y)][i]=true;
				a[x][y]=i;
				if(go(z+1)) return true;
				c[x][i]=c2[y][i]=c3[square(x,y)][i]=false;
				a[x][y]=0;
			}
		}
	}
	
	return false;
}

int main() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin>>a[i][j];
			
			if(a[i][j]!=0) {
				c[i][a[i][j]]=true;
				c2[j][a[i][j]]=true;
				c3[square(i,j)][a[i][j]]=true;
			}
		}
	}
	
	go(0);
	return 0;
}

/*
boj.kr/2580

INPUT:
0 3 5 4 6 9 2 7 8
7 8 2 1 0 5 6 0 9
0 6 0 2 7 8 1 3 5
3 2 1 0 4 6 8 9 7
8 0 4 9 1 3 5 0 6
5 9 6 8 2 0 4 1 3
9 1 7 6 5 2 0 8 0
6 0 3 7 0 1 9 5 2
2 5 8 3 9 4 7 6 0

OUTPUT:
1 3 5 4 6 9 2 7 8
7 8 2 1 3 5 6 4 9
4 6 9 2 7 8 1 3 5
3 2 1 5 4 6 8 9 7
8 7 4 9 1 3 5 2 6
5 9 6 8 2 7 4 1 3
9 1 7 6 5 2 3 8 4
6 4 3 7 8 1 9 5 2
2 5 8 3 9 4 7 6 1
*/
