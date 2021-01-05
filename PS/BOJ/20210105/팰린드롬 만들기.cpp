/* reference: https://privatedevelopnote.tistory.com/58 */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 5e3 + 10;

int N;
int a[MAX_N];
int d[MAX_N][MAX_N];

int go(int L, int R) {
	if(L == R || L - 1 == R) return 0;
	
	int& ret = d[L][R];
	if(ret != -1) return ret;
	ret = 0;
	
	if(a[L] == a[R]) ret += go(L + 1, R - 1);
	else ret += min(go(L + 1, R) + 1, go(L, R - 1) + 1);
	
	return ret;
}

int main() {
	cin >> N;
	
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	memset(d, -1, sizeof(d));
	cout << go(1, N) << '\n';
	
	return 0;
}
