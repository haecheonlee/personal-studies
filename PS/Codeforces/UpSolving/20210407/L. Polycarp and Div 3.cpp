/* refernece: editorial */

#include <iostream>
#include <vector>

#define sz(x) (int)x.size()

using namespace std;

const int MAX_N = 2e5 + 10;

bool check[MAX_N];

int main() {
	string s; cin >> s;
	int N = sz(s);
	
	int r = 0;
	vector<int> fin(3, -1);
	fin[0] = 0;
	
	vector<int> z(N + 1);
	for(int i = 1; i <= N; i++) {
		r = (r + s[i - 1] - '0') % 3;
		z[i] = z[i - 1];
		
		if(fin[r] != -1) z[i] = max(z[i], z[fin[r]] + 1);
		fin[r] = i;
	}
	cout << z[N] << '\n';
	
	return 0;
}
