#include <iostream>
#include <cstring>

using namespace std;

const int MAX=1e3+1;
const int MOD=1e9+7;

int N,M;
int cache[MAX][MAX];

int go(int x, int y) {
	if(N<x || M<y) return 0;
	if(x==N && y==M) return 1;
	
	int& ret=cache[x][y];
	if(ret!=-1) return ret;
	ret=0;
	
	// right
	ret+=go(x, y+1);
	ret%=MOD;
	
	// dig
	ret+=go(x+1, y+1);
	ret%=MOD;
	
	// bottom
	ret+=go(x+1, y);
	ret%=MOD;
	
	return ret;
}

int main() {
	cin>>N>>M;
	
	memset(cache, -1, sizeof(cache));
	cout<<go(1,1);
}
