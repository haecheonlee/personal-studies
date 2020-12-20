#include <iostream>
#include <cstring>

#define sz(x) (int)(x.size())

using namespace std;

const int MAX = 1e3 + 1;

string s, t;
int d[MAX][MAX];

int go(int i, int j) {
	if(i == sz(s)) return sz(t) - j;
	if(j == sz(t)) return sz(s) - i;
	
	int& ret = d[i][j];
	if(ret != -1) return ret;
	ret = 1e9;
	
	if(s[i] == t[j]) {
		ret = min(ret, go(i + 1, j + 1));
	} else {
		// insert
		ret = min(ret, go(i, j + 1) + 1);
		
		// delete
		ret = min(ret, go(i + 1, j) + 1);
		
		// replace
		ret = min(ret, go(i + 1, j + 1) + 1);
	}
	
	return ret;
}

int main() {
	cin >> s >> t;
	
	memset(d, -1, sizeof(d));
	cout << go(0, 0);
	
	return 0;
}
