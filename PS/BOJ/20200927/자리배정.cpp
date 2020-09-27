#include <iostream>

using namespace std;

const int MAX=1e3+1;

int a[MAX][MAX];

int main() {
	int N,M,K;
	cin>>M>>N>>K;
	
	int x=N, y=1, UR=1, DL=1, num=1;
	bool up_right=true;

	while(num<N*M) {
		if(up_right) {
			while(x>=UR) {
				a[x][y]=num++;
				x--;
			}
			
			x++, y++;
			while(y<=(M-(UR-1))) {
				a[x][y]=num++;
				y++;
			}
			x++, y--;
			
			UR++;
			up_right=false;
		} else {
			while(x<=(N-(DL-1))) {
				a[x][y]=num++;
				x++;
			}
			
			x--, y--;
			while(y-1>=DL) {
				a[x][y]=num++;
				y--;
			}
			x--, y++;
			
			DL++;
			up_right=true;
		}
	}
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			if(a[i][j]==K) {
				cout<<j<<' '<<N-i+1;
				return 0;
			}
		}
	}
	
	cout<<0;

	return 0;
}
