#include <iostream>
#include <cstring>

using namespace std;
using ll=long long;

const int MAX=3e2+1;

int N,M;
ll cache[MAX][MAX];
bool check[MAX][MAX];

ll go(int x, int y, int t, ll eaten) {
	if(MAX<=x || MAX<=y) return eaten;
	
	ll& ret=cache[x][y];
	if(ret!=-1) return ret;
	ret=0;

	ll candy=(check[x][y] ? max(0, M-t) : 0);
	ret=max(go(x+1, y, t+1, eaten) + candy, go(x, y+1, t+1, eaten) + candy);

	return ret;
}

int main() {
	cin>>N>>M;
	
	for(int i=0; i<N; i++) {
		int x,y;
		cin>>x>>y;
		
		check[x][y]=true;
	}

	memset(cache, -1, sizeof(cache));
	cout<<go(0,0,0,0);

	return 0;
}
