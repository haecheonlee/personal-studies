/* editorial: CodeWithDemoralizer */

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 2e5 + 10;

int N, M;
string s, ss;
int L[MAX], R[MAX];

int main() {
	cin >> N >> M;
	cin >> s >> ss;
	
	int i = 0, j = 0;
	while(j < M) {
		while(s[i] != ss[j]) i++;
		L[j] = i;
		i++, j++;
	}
	
	i = N - 1, j = M - 1;
	while(j >= 0) {
		while(s[i] != ss[j]) i--;
		R[j] = i;
		i--, j--;
	}
	
	int ans = 0;
	for(int i = 1; i < M; i++) ans = max(ans, R[i] - L[i - 1]);
	cout << ans << '\n';
	
	return 0;
}
