/* reference: baekjoon/codeplus */

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX=1e3+2;
const int INF=1e9;

int a[MAX][MAX];
int d[MAX][MAX][3];

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) cin>>a[i][j];
	}
	
	fill(&d[0][0][0], &d[1001][1001][2]+1, -INF);
	d[1][1][1]=a[1][1];
	for(int j=2; j<=M; j++) d[1][j][1]=d[1][j-1][1]+a[1][j];
	
	for(int i=2; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			d[i][j][0] = max({d[i-1][j][0], d[i-1][j][1], d[i-1][j][2]}) + a[i][j];
			d[i][j][1] = max(d[i][j-1][0], d[i][j-1][1]) + a[i][j];
		}
		
		for(int j=M; j>=1; j--) {
			d[i][j][2] = max(d[i][j+1][0], d[i][j+1][2]) + a[i][j];
		}
	}

	cout<<max({d[N][M][0], d[N][M][1], d[N][M][2]});

	return 0;
}
