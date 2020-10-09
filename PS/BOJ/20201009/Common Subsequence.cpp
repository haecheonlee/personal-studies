/* reference: https://webfirewood.tistory.com/118 */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX=1e3+1;

int d[MAX][MAX];

int main() {
	string a,b;
	
	while(cin>>a>>b) {
		int N=a.size();
		int M=b.size();
		
		memset(d, 0, sizeof(d));
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=M; j++) {
				if(a[i-1]==b[j-1]) {
					d[i][j]=d[i-1][j-1]+1;
				} else {
					d[i][j]=max(d[i-1][j], d[i][j-1]);
				}
			}
		}
		
		cout<<d[N][M]<<'\n';
	}
	
	return 0;
}
