#include <iostream>

using namespace std;

long long calc(int N) {
	long long ans = 0;
	for(int start = 1, len = 1; start <= N; start *= 10, len++) {
		int end = start * 10 - 1;
		if(end > N) end = N;
		
		ans += (long long)(end - start + 1) * len;
	}
	
	return ans;
}

int main() {
	int K; cin >> K;
	int N = K;
	
	int L = 1, R = N, ans = 0;
	while(L <= R) {
		int mid = (L + R) / 2;
		long long len = calc(mid);
		
		if(K <= len) ans = mid, R = mid - 1;
		else L = mid + 1;
	}
	
	string s = to_string(ans);
	long long x = calc(ans);
	cout << s[s.size() - (x - K) - 1] << '\n';
	
	return 0;
}
