#include <iostream>
#include <cstring>

using namespace std;

const int MAX=1e2 + 1;
const int MOD=1e4 + 7;

int N;
int d[MAX][MAX][MAX];
int dx[]={0,1,0,1};
int dy[]={0,0,1,1};

int go(int ground, int a, int b) {
	if((ground > 1 && a == b) || a > ground || b > ground) return 0;
	if(ground == N) return 1;
	
	int& ret = d[ground][a][b];
	if(ret != -1) return ret;
	ret = 0;
	
	for(int k = 0; k < 4; k++) {
		ret += go(ground + 1, a + dx[k], b + dy[k]); 
		ret %= MOD;
	}
	
	return ret;
}

int main() {
	cin>>N;
	
	memset(d, -1, sizeof(d));
	cout<<go(1,1,1);

	return 0;
}
