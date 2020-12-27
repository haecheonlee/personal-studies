/* reference: https://sys09270883.github.io/ps/6/#17951%EB%B2%88-%ED%9D%A9%EB%82%A0%EB%A6%AC%EB%8A%94-%EC%8B%9C%ED%97%98%EC%A7%80-%EC%86%8D%EC%97%90%EC%84%9C-%EB%82%B4-%ED%8F%89%EC%A0%90%EC%9D%B4-%EB%8A%90%EA%BB%B4%EC%A7%84%EA%B1%B0%EC%95%BC */

#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 1;

int N, K, ans;
int a[MAX_N];

bool chk(int mid) {
	int sum = 0, m = 1e9, cnt = 1;
	
	for(int i = 0; i < N; i++) {
		sum += a[i];
		
		if(sum >= mid) {
			m = min(m, sum);
			sum = 0, cnt++;
		}
		
		if(cnt > K) {
			ans = max(ans, m);
			return true;
		}
	}
	
	return false;
}

int main() {
	cin >> N >> K;
	
	for(int i = 0; i < N; i++) cin >> a[i];

	int L = 1, R = 1e9;
	while(L <= R) {
		int mid = (L + R) / 2;
		
		if(chk(mid)) L = mid + 1;
		else R = mid - 1;
	}
	
	cout << ans << '\n';
	
	return 0;
}
