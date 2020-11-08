#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	int a[N];
	for(int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N);
	
	if(N&1) cout << a[N / 2];
	else cout << a[N / 2 - 1];
	
	return 0;
}
