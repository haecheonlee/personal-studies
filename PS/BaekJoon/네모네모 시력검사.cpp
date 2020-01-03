#include <iostream>

using namespace std;

int main() {
	int start_x=-1, start_y=-1, end_x=-1, end_y=-1;
	
	int N, M;
	cin>>N>>M;
	
	string s[N];
	for(int i=0; i<N; i++) {
		cin>>s[i];
	}
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(s[i][j] == '#') {
				if(start_x == -1 && start_y == -1) { start_y=i; start_x=j; }
				end_y=i;end_x=j;
			}
		}
	}
	
	bool top = (s[start_y][start_x+((end_x-start_x+1)/2)] == '.');
	bool right = (s[start_y+((end_y-start_y+1)/2)][end_x] == '.');
	bool bottom = (s[end_y][start_x+((end_x-start_x+1)/2)] == '.');
	bool left = (s[start_y+((end_y-start_y+1)/2)][start_x] == '.');
	
	if(top) cout<<"UP";
	if(right) cout<<"RIGHT";
	if(bottom) cout<<"DOWN";
	if(left) cout<<"LEFT";
	
	return 0;
}

/*
boj.kr/18242

INPUT:
8 10
..........
..........
...##.##..
...#...#..
...#...#..
...#...#..
...#####..
..........

OUTPUT:
UP
*/
