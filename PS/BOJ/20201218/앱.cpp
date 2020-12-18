/* reference: minshogi	 */

#include <iostream>

using namespace std;

const int MAX = 1e2 + 1;

int memory[MAX], cost[MAX];
int d[MAX * MAX];

int main() {
	int N, M;
	cin >> N >> M;
	
	for(int i = 0; i < N; i++) cin >> memory[i];
	for(int i = 0; i < N; i++) cin >> cost[i];
	
	for(int i = 0; i < N; i++) {
		for(int j = 10000; j >= cost[i]; j--) d[j] = max(d[j], d[j - cost[i]] + memory[i]);
	}
	
	int ans = 1e9;
	for(int i = 0; i <= 10000; i++) if(d[i] >= M) ans = min(ans, i);
	cout << ans << '\n';
	
	return 0;
}
