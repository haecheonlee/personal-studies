/* reference: baekjoon/codeplus */

#include <iostream>
#include <cstring>

#define sz(x) (int)(x.size())

using namespace std;

const int MAX = 1e4 + 1;

string N;
int M;
int d[MAX][101];

int go(string n, int m) {
	if(m == M + 1) return n > N;
	
	int x = stoi(n);
	int& ret = d[x][m];
	if(ret != -1) return ret;
	ret = ((m % 2) == 0);
	
	for(int i = 0; i < sz(n); i++) {
		string temp = n;
		
		if(temp[i] == '9') temp[i] = '0';
		else temp[i] += 1;
		
		if(m % 2 == 0) ret &= go(temp, m + 1);
		else ret |= go(temp, m + 1);
	}
	
	return ret;
}

int main() {
	cin >> N >> M;
	
	memset(d, -1, sizeof(d));
	cout << (go(N, 1) ? "koosaga" : "cubelover");
	
	return 0;
}
