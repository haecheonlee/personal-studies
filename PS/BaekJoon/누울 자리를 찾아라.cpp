#include <iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	char room[n][n];
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) cin>>room[i][j];
	}

	int h=0,v=0;
	for(int i=0; i<n; i++) {
		int count=0;
		for(int j=0; j<n; j++) {
			if(room[i][j]=='.') {
				count++;
			} else {
				if(count>=2) h++;
				count=0;
			}
		}
		if(count>=2) h++;
	}
	
	for(int j=0; j<n; j++) {
		int count=0;
		for(int i=0; i<n; i++) {
			if(room[i][j]=='.') {
				count++;
			}
			else {
				if(count>=2) v++;
				count=0;
			}
		}
		if(count>=2) v++;
	}
	
	cout<<h<<" "<<v;

	return 0;
}

/*
boj.kr/1652

INPUT:
5
....X
..XX.
.....
.XX..
X....

OUTPUT:
5 4
*/
