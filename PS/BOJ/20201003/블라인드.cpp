#include <iostream>

using namespace std;

const int MAX=502;

char a[MAX][MAX];

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<N*5+1; i++) {
		for(int j=0; j<M*5+1; j++) cin>>a[i][j];
	}
	
	int ans[5] {0, 0, 0, 0, 0};
	for(int i=1; i<N*5+1; i+=5) {
		for(int j=1; j<M*5+1; j+=5) {
			int x;
			for(x=i; x<=i+3; x++) {
				if(a[x][j]=='.') break;
			}
			
			int H=4-(i+4-x);
			ans[H]++;
		}
	}

	for(int i=0; i<5; i++) cout<<ans[i]<<' ';
	
	return 0;
}
