#include <iostream>
#include <cstring>

using namespace std;

const int MAX=1e5+1;

int N,M;
int cache[MAX][11];
int a[11][MAX];

int go(int day, int eaten) {
	// base case
	if(day>N) return 0;
	
	// caching
	int& ret=cache[day][eaten];
	if(ret!=-1) return ret;
	ret=0;
	
	for(int k=1; k<=M; k++) {
		int happiness=a[k][day];
		if(k==eaten) happiness/=2;
		
		ret=max(ret, go(day+1, k) + happiness);	
	}
	
	return ret;
}

int main() {
	cin>>N>>M;
	
	for(int i=1; i<=M; i++) {
		for(int j=1; j<=N; j++) cin>>a[i][j];
	}
	
	memset(cache, -1, sizeof(cache));
	cout<<go(1,0);
	
	return 0;
}
