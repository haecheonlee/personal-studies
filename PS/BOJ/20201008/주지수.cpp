/* reference: boj.kr/11660 */
#include <iostream>

using namespace std;

const int MAX=1025;

int a[MAX][MAX];
int p[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin>>N>>M;

	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			cin>>a[i][j];
			p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];	
		}
	}
	
	int K;
	cin>>K;
	
	while(K--) {
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		
		cout<<p[x2][y2]-p[x2][y1-1]-p[x1-1][y2]+p[x1-1][y1-1]<<'\n';
	}

	return 0;
}
