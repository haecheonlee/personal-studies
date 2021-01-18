/* reference: baekjoon/codeplus */

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

const int MAX = 20;

int N;
double a[MAX][MAX];
double d[1 << MAX];
bool check[1 << MAX];

double go(int i, int state) {
	if(i == N) return 1.0;
	if(check[state]) return d[state];
	check[state] = true;

	double& ret = d[state];
	for(int k = 0; k < N; k++) {
		if(state & (1 << k)) continue;
		ret = max(ret, go(i + 1, state | (1 << k)) * a[i][k]);
	}
	
	return ret;
}

int main() {
	cin >> N;
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> a[i][j];
			a[i][j] /= 100;
		}
	}

	cout << fixed << setprecision(6) << go(0, 0) * 100 << '\n';
	
	return 0;
}
