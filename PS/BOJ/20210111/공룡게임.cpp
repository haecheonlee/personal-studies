#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 1e3 + 1;
const int MOD = 1e9 + 7;

int N;
int d[MAX_N][3][3][2];

int go(int n, int p, int pp, bool check) {
	if(p + pp >= 4) return 0;
	if(n == N) return check;
	
	int& ret = d[n][p][pp][check];
	if(ret != -1) return ret;
	ret = 0;
	
	if(p && pp) {
		ret = (ret + go(n + 1, 0, p, check) % MOD) % MOD;
	} else {
		for(int i = 0; i <= 2; i++) 
			ret = (ret + go(n + 1, i, p, check | (i == 2)) % MOD) % MOD;
	}
	
	return ret;
}

int main() {
	cin >> N;
	
	memset(d, -1, sizeof(d));
	cout << go(1, 0, 0, false) << '\n';
	
	return 0;
}
