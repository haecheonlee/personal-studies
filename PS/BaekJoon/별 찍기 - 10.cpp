/* reference: https://blog.naver.com/moonsoo5522/220706431458 */

#include <iostream>
#include <cstring>

using namespace std;

char ans[2200][2200];

void solve(int x, int y, int size) {
	if(size==1) {
		ans[x][y]='*';
		return;
	}
	
	int N=size/3;
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if(i==1 && j==1) continue;
			solve(x+(i*N),y+(j*N),N);
		}
	}
}

int main() {
	int N;
	cin>>N;
	
	memset(ans,' ',sizeof(ans));
	solve(0,0,N);
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) cout<<ans[i][j];
		cout<<'\n';
	}
	
	return 0;
}
