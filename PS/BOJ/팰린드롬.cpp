/* reference: https://blog.naver.com/programmer18/220922121641 */

#include <iostream>
#include <algorithm>

#define sz(x) (int)(x.size())

using namespace std;

const int MAX_N = 5e3 + 1;

int d[MAX_N][MAX_N];

int main() {
	int N;
	cin >> N;
	
	string s, ss;
	cin >> s;
	
	// reverse
	ss = s;
	reverse(ss.begin(), ss.end());
	
	for(int i = 0; i <= sz(s); i++) {
		for(int j = 0; j <= sz(ss); j++) {
			if(i == 0 || j == 0) d[i][j] = 0;
			else if(s[i - 1] == ss[j - 1]) d[i][j] = d[i - 1][j - 1] + 1;
			else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
		}
	}
	
	cout << N - d[N][N];
	
	return 0;
}
