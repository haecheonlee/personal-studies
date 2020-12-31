/* reference: https://jason9319.tistory.com/253 */

#include <iostream>
#include <vector>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int MAX = 4e5 + 1;
const int M = 2e5;

bool sum[MAX];

int main() {
	fastio
	
	int N;
	cin >> N;
	
	int ans = 0;
	vector<int> a(N);
	for(int i = 0; i < N; i++) {
		cin >> a[i];
		
		for(int j = 0; j < i; j++) if(sum[a[i] - a[j] + M]) { ans++; break; }
		for(int j = 0; j <= i; j++) sum[a[i] + a[j] + M] = true;
	}
	cout << ans << '\n';

	return 0;
}
