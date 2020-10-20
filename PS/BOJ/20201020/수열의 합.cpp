#include <iostream>

using namespace std;

const int MAX=1e3+1;

int a[MAX][MAX];
int ans[MAX];

int main() {
	int N;
	cin>>N;
	
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) cin>>a[i][j];
	}
	
	if(N<=2) {
		ans[1]=a[1][2]/2;
		ans[2]=a[1][2]-ans[1];
		cout<<ans[1]<<' '<<ans[2];
	} else {
		ans[1]=(a[1][2]+a[1][3]-a[2][3])/2;
		for(int i=2; i<=N; i++) ans[i]=a[i][1]-ans[1];
		for(int i=1; i<=N; i++) cout<<ans[i]<<' ';
	}
	
	return 0;
}
