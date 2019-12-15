#include <iostream>

using namespace std;

int main() {
	int H, W;
	cin>>H>>W;
	
	char l[H][W];
	for(int i=0; i<H; i++) {
		for(int j=0; j<W; j++) {
			cin>>l[i][j];
		}
	}
	
	for(int i=0; i<H; i++) {
		int current = -1; 
		for(int j=0; j<W; j++) {
			if(l[i][j] == 'c') current = 0;
			else if(l[i][j] == '.') {
				if(current != -1) current++;
			}
			cout<<current<<" ";
		}
		cout<<endl;
	}

	return 0;
}

/*
boj.kr/10709

INPUT:
6 8
.c......
........
.ccc..c.
....c...
..c.cc..
....c...

OUTPUT:
-1 0 1 2 3 4 5 6
-1 -1 -1 -1 -1 -1 -1 -1
-1 0 0 0 1 2 0 1
-1 -1 -1 -1 0 1 2 3
-1 -1 0 1 0 0 1 2
-1 -1 -1 -1 0 1 2 3
*/
