/* reference: anb from study */

#include <iostream>
#include <cstring>

#define sz(x) (int)(x.size())

using namespace std;

const int MAX = 51;

string s;
int d[MAX][MAX];

int go(int L, int R) {
	if(L >= R) return 0;
   
	int& ret = d[L][R];
	if(ret != -1) return ret;
	ret = 1e9;
	
	if(s[L] == s[R]) ret = go(L + 1, R - 1);
    else ret = go(L + 1, R - 1) + 1;
    
	ret = min(ret, min(go(L + 1, R) + 1, go(L, R - 1) + 1));
	
	return ret;
}

int main() {
	cin >> s;
	int LEN = sz(s);

	memset(d, -1, sizeof(d));
	int ans = go(0, LEN - 1);

	for(int i = 0; i < LEN; i++) {
		for(int j = i + 1; j < LEN; j++) {
			swap(s[i], s[j]);
			
			memset(d, -1, sizeof(d));
			ans = min(ans, go(0, LEN - 1) + 1);
			
			swap(s[i], s[j]);
		}
	}

	cout << ans;

	return 0;
}
