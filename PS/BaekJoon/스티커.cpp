#include <iostream>

using namespace std;

int DP[100001][3];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T, n;
	cin>>T;
	
	for(int i=0; i<T; i++) {
		cin>>n;
		
		int stickers[2+1][n+1];
		for(int x=1; x<=2; x++) {
			for(int j=1; j<=n; j++) {
				cin>>stickers[x][j];
			}
		}
		
		DP[1][0]=0;
		DP[1][1]=stickers[1][1];
		DP[1][2]=stickers[2][1];
		
		for(int j=2; j<=n; j++) {
			DP[j][0]=max(max(DP[j-1][0], DP[j-1][1]), DP[j-1][2]);
			DP[j][1]=max(DP[j-1][0], DP[j-1][2])+stickers[1][j];
			DP[j][2]=max(DP[j-1][0], DP[j-1][1])+stickers[2][j];
		}
		
		cout<<max(max(DP[n][0], DP[n][1]), DP[n][2])<<'\n';
	}

	return 0;
}

/*
boj.kr/9465

INPUT:
2
5
50 10 100 20 40
30 50 70 10 60
7
10 30 10 50 100 20 40
20 40 30 50 60 20 80

OUTPUT:
260
290
*/
