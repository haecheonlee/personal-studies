#include <iostream>
#include <cstring>

using namespace std;

const int INF=1e9+1;
const int MAX=1e3+1;

int N,M;
int a[MAX];	// distance
int b[MAX];	// weather
int cache[MAX][MAX][3];	// 1: move, 2: stay

int go(int city, int weather, int selection) {
	if(city>N) return 0;
	if(weather>M) return INF;
	
	int& ret=cache[city][weather][selection];
	if(ret!=-1) return ret;
	ret=INF;
	
	ret=min(ret, go(city+1, weather+1, 1) + a[city+1] * b[weather+1]);	//	move
	ret=min(ret, go(city, weather+1, 2));	//	stay;
	
	return ret;
}

int main() {
	cin>>N>>M;
	
	for(int i=1; i<=N; i++) cin>>a[i];
	for(int i=1; i<=M; i++) cin>>b[i];
	
	memset(cache, -1 ,sizeof(cache));
	cout<<go(0,0,0);
	
	return 0;
}
