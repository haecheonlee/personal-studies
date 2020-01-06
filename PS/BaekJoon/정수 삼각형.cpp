#include <iostream>

using namespace std;

int DP[501][501]{0};
int main() {
	int n;
	cin>>n;
	
	int m=-1;
	for(int i=1; i<=n; i++) {
		int num;
		
		if(i==1) {
			cin>>num;
			DP[i][1]=num;
			continue;
		}
		
		for(int j=1; j<=i; j++) {
			cin>>num;

			if(j==i) {
				DP[i][j]=DP[i-1][j-1]+num;
			} else if(j>1) {
				DP[i][j]=max(DP[i-1][j-1], DP[i-1][j])+num;
			} else {
				DP[i][j]=DP[i-1][j]+num;
			}
				
			m=max(m, DP[i][j]);
		}
	}
	
	cout<<m;
	return 0;
}

/*
boj.kr/1932

INPUT:
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

OUTPUT:
30
*/
