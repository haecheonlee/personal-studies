#include <iostream>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	int DP[N+1][3];
	for(int i=1;i<=N; i++) {
		int colors[3];
		for(int j=0; j<3; j++) {
			cin>>colors[j];
		}
		
		if(i>1) {
			DP[i][0] = colors[0] + (min(DP[i-1][1], DP[i-1][2]));
			DP[i][1] = colors[1] + (min(DP[i-1][0], DP[i-1][2]));
			DP[i][2] = colors[2] + (min(DP[i-1][0], DP[i-1][1]));
		} else {
			DP[i][0] = colors[0];
			DP[i][1] = colors[1];
			DP[i][2] = colors[2];
		}
	}
	
	cout<<min(min(DP[N][0], DP[N][1]), DP[N][2]);
	return 0;
}

/*
boj.kr/1149

INPUT:
3
26 40 83
49 60 57
13 89 99

OUTPUT:
96
*/
