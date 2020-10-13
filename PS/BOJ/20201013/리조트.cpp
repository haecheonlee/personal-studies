#include <iostream>
#include <cstring>

using namespace std;

const int MAX=1e2+1;
const int INF=2e9;
const int price[] = { 10000, 25000, 37000 };

int N,M;
int cache[MAX][MAX];
bool check[MAX];

int go(int n, int m) {
	if(n>N) return 0;
	
	int& ret=cache[n][m];
	if(ret!=-1) return ret;
	ret=INF;
	
	if(check[n]==false) {
		// 1-day
		if(m>=3) {
			ret=min(ret, go(n+1, m-3));
		} else {
			ret=min(ret, go(n+1, m) + price[0]);	
		}
		
		// 3-day
		ret=min(ret, go(n+3, m+1) + price[1]);
		
		// 5-day
		ret=min(ret, go(n+5, m+2) + price[2]);
	} else {
		ret=min(ret, go(n+1, m));
	}
	
	return ret;
}

int main() {
	cin>>N>>M;
	
	for(int i=0; i<M; i++) {
		int x;
		cin>>x;

		check[x]=true;
	}

	memset(cache, -1, sizeof(cache));
	cout<<go(1,0);
	
	return 0;
}
