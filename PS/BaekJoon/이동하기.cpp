#include <iostream>

using namespace std;

int main() {
	int N,M;
	cin>>N>>M;
	
	int l[N+1][M+1];
	
	int n;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			cin>>l[i][j];
			
			if(j>1 && i>1) {
				l[i][j]+=max(l[i-1][j], l[i][j-1]);
			} else if(j==1) {
				if(i>1) l[i][j]+=l[i-1][j];
			} else if(i==1) {
				if(j>1) l[i][j]+=l[i][j-1];
			}
		}
	}

	cout<<l[N][M];
	return 0;
}

/*
boj.kr/11048

INPUT:
4 3
1 2 3
6 5 4
7 8 9
12 11 10

OUTPUT:
47
*/
