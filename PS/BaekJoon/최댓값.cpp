#include <iostream>

using namespace std;

int main() {
	int l[9][9];
	
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			cin>>l[i][j];
		}
	}
	
	int max = -1;
	int row, col;
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			if(max < l[i][j]) {
				max = l[i][j];
				row = i+1;
				col = j+1;
			}
		}
	}
	
	cout<<max<<endl;
	cout<<row<<" "<<col;

	return 0;
}

/*
boj.kr/2566

INPUT:
3 23 85 34 17 74 25 52 65
10 7 39 42 88 52 14 72 63
87 42 18 78 53 45 18 84 53
34 28 64 85 12 16 75 36 55
21 77 45 35 28 75 90 76 1
25 87 65 15 28 11 37 28 74
65 27 75 41 7 89 78 64 39
47 47 70 45 23 65 3 41 44
87 13 82 38 31 12 29 29 80

OUTPUT:
90
5 7
*/
