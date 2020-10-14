#include <iostream>
#include <cstring>

using namespace std;

const int MAX=1e2+1;

string P;
string A[2];
int cache[MAX][25][2];

int go(int now, int L, int level) {
	if(L==P.size()) return 1;
	
	int& ret=cache[now][L][level];
	if(ret!=-1) return ret;
	ret=0;
	
	for(int i=now; i<A[level].size(); i++) {
		if(A[level][i]==P[L]) ret+=go(i+1, L+1, 1-level);
	}
	
	return ret;
}

int main() {
	cin>>P>>A[0]>>A[1];

	memset(cache, -1, sizeof(cache));
	cout<<go(0,0,0)+go(0,0,1);
	
	return 0;
}
