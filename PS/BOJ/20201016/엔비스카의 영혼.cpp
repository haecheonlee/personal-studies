#include <iostream>
#include <cstring>

using namespace std;

const int MAX=1e6+1;
const int INF=1e9;

int N,a,b;
int cache[MAX];

int go(int now) {
	if(now==N) return 0;
	
	int& ret=cache[now];
	if(ret!=-1) return ret;
	ret=INF;
	
	// stay
	ret=min(ret, go(now+1) + 1);
	
	// a
	if(now+a+1<=N) ret=min(ret, go(now+a+1)+1);
	
	// b
	if(now+b+1<=N) ret=min(ret, go(now+b+1)+1);
	
	return ret;
}

int main() {
	cin>>N>>a>>b;

	memset(cache, -1, sizeof(cache));	
	cout<<go(0);
	
	return 0;
}
