#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 60;

ll d[MAX_N];

int main() {
	int N; cin >> N;
	d[1] = 2;
	for(int i = 2; i <= N; i++) d[i] = d[i - 1] + (d[i - 1] - d[i - 2]) * 2;
	cout << d[N] << '\n';
	
	return 0;
}
