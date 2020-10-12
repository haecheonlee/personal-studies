#include <iostream>
#include <cstring>

using namespace std;

const int MAX=1e3+1;
const int MOD=1e6;

int N;
int cache[MAX][10][4][4];
	
int go(int n, int a, int latest, int newest) {
	if(a>=2) return 0;
	if(n>N) return 1;
	
	int& ret=cache[n][a][latest][newest];
	if(ret!=-1) return ret;
	ret=0;
	
	// 출석 (1)
	ret+=go(n+1, a, newest, 1)%MOD;
	ret%=MOD;
	
	// 지각 (2)
	ret+=go(n+1, a+1, newest, 2)%MOD;
	ret%=MOD;
	
	// 결석 (3)
	if(!(latest==3 && newest==3)) {
		ret+=go(n+1, a, newest, 3)%MOD;
		ret%=MOD;
	} 

	return ret;
}

int main() {
	cin>>N;
	
	memset(cache, -1, sizeof(cache));
	cout<<go(1,0,0,0);

	return 0;
}
