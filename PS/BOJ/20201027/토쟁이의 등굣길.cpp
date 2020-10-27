#include <iostream>
#include <cstring>

using namespace std;

const int MAX=2e2+1;
const int MOD=1e6+7;

int N,M,tx,ty;
int d[MAX][MAX][2];

int go(int x, int y, int check) {
	if(x>N || y>M) return 0;
	if(x==N && y==M) return check;
	
	int& ret=d[x][y][check];
	if(ret!=-1) return ret;
	ret=0;
	
	if(tx==x && ty==y) check=1;
	ret+=go(x+1, y, check)%MOD;
	ret%=MOD;
	
	ret+=go(x, y+1, check)%MOD;
	ret%=MOD;
	
	return ret;
}

int main() {
	cin>>M>>N>>ty>>tx;
	
	memset(d, -1, sizeof(d));
	cout<<go(1,1,0);

	return 0;
}
