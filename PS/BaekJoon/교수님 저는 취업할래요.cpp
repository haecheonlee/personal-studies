#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	int l[N][N];
	
	int p_x=-1, p_y=-1, s_x=-1, s_y=-1;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cin>>l[i][j];
			if(l[i][j]==5) { p_x=j; p_y=i; }
			if(l[i][j]==2) { s_x=j; s_y=i; }
		}
	}
	
	double distance = sqrt(pow(p_x-s_x, 2)+pow(p_y-s_y, 2));

	int count=0;
	if(distance>=5) {
		for(int i=min(p_y, s_y); i<=max(p_y, s_y); i++) {
			for(int j=min(p_x, s_x); j<=max(p_x, s_x); j++) {
				if(l[i][j]==1) count++;
			}
		}
	}
	
	if(count>=3) cout<<1;
	else cout<<0;

	return 0;
}

/*
boj.kr/18221

INPUT:
10
0 5 0 0 0 0 1 0 0 0
0 1 0 0 0 0 1 0 0 0
0 0 0 0 0 0 2 0 0 0
0 0 1 1 0 0 1 0 0 0
1 0 0 0 0 0 0 0 0 0
0 0 1 0 1 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

OUTPUT:
1
*/
