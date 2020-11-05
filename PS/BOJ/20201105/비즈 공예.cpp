/* reference: https://hsdevelopment.tistory.com/555 */

#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAX = 6;

int N;
int a[MAX];
ll d[11][11][11][11][11][MAX][MAX];

ll go(int b1, int b2, int b3, int b4, int b5, int p, int pp) {
	if(b1 == 0 && b1 == b2 && b2 == b3 && b3 == b4 && b4 == b5) return 1;

	ll& ret = d[b1][b2][b3][b4][b5][p][pp];
	if(ret != -1) return ret;
	ret = 0;

	if(b1 - 1 >= 0 && p != 1 && pp != 1) ret += go(b1 - 1, b2, b3, b4, b5, 1, p);
	if(b2 - 1 >= 0 && p != 2 && pp != 2) ret += go(b1, b2 - 1, b3, b4, b5, 2, p);
	if(b3 - 1 >= 0 && p != 3 && pp != 3) ret += go(b1, b2, b3 - 1, b4, b5, 3, p);
	if(b4 - 1 >= 0 && p != 4 && pp != 4) ret += go(b1, b2, b3, b4 - 1, b5, 4, p);
	if(b5 - 1 >= 0 && p != 5 && pp != 5) ret += go(b1, b2, b3, b4, b5 - 1, 5, p);
	
	return ret;
}

int main() {
	cin >> N;
	
	for(int i = 1; i <= N; i++) cin >> a[i];

	memset(d, -1, sizeof(d));
	cout << go(a[1], a[2], a[3], a[4], a[5], 0, 0);	

	return 0;
}
