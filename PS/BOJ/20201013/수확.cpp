#include <iostream>
#include <cstring>

using namespace std;

const int MAX=2e3+1;

int N;
int a[MAX];
int cache[MAX][MAX];

int go(int s, int e, int k) {
	if(k>N) return 0;
	
	int& ret=cache[s][e];
	if(ret!=-1) return ret;
	ret=0;
	
	ret=max(ret, go(s+1, e, k+1) + a[s] * k);
	ret=max(ret, go(s, e-1, k+1) + a[e] * k);
	
	return ret;
}

int main() {
	cin>>N;
	
	for(int i=1; i<=N; i++) cin>>a[i];

	memset(cache, -1, sizeof(cache));
	cout<<go(1,N,1);

	return 0;
}
