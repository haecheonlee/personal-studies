/* reference: eotkd4791 */

#include <iostream>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

using namespace std;

const int MAX = 1e6 + 1;
const int MAXX = 3e5 + 1;

int N;
int a[MAXX][3];
bool check[MAX];

int main() {
	fastio
	cin >> N;	

	for(int i = 1; i <= N; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
	
	int ans = 0;
	for(int i = 1; i <= N; i++) {
		if(!check[a[i][0]] && !check[a[i][1]] && !check[a[i][2]]) ans++;

		check[a[i][0]] = check[a[i][1]] = check[a[i][2]] = 1;
	}
	cout << ans << '\n';

	return 0;
}
