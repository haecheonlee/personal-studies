/* reference: lyzqm */

#include <iostream>
#include <cstring>

using namespace std;

const int MOD=1e4;
const int MAX=1e2+1;

int N,K;
int cache[MAX][4][4];
int p[MAX];

int go(int day, int latest, int newest) {
	if(day>N) return 1;
	
	int& ret=cache[day][latest][newest];
	if(ret!=-1) return ret;
	ret=0;
	
	if(p[day]) {
		if(latest==newest && newest==p[day]) return 0;
		ret=go(day+1, newest, p[day])%MOD;
		ret%=MOD;
	} else {
		for(int i=1; i<=3; i++) {
			if(latest==newest && newest==i) continue;
			ret+=go(day+1, newest, i)%MOD;
			ret%=MOD;
		}
	}
	
	return ret;
}

int main() {
	cin>>N>>K;
	
	for(int i=0; i<K; i++) {
		int a,b;
		cin>>a>>b;
		
		p[a]=b;
	}
	
	memset(cache, -1, sizeof(cache));
	cout<<go(1,0,0);
	
	return 0;
}
