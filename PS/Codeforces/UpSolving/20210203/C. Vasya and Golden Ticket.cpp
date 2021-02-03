#include <iostream>

using namespace std;

int main() {
	int N; scanf("%d", &N);
	int a[N + 1];
	for(int i = 1; i <= N; i++) scanf("%1d", &a[i]);

	int sum = 0;
	for(int i = 1; i <= N - 1; i++) {
		sum += a[i];
		
		bool is_good = 0;
		int now = 0;
		for(int j = i + 1; j <= N; j++) {
			now += a[j];
			
			if(now > sum) {
				is_good = 0;
				break;
			} else if(now == sum) {
				is_good = 1;
				now = 0;
			}
		}
		
		if(is_good && !now) {
			cout << "YES" << '\n';
			return 0;
		}
	}
	
	cout << "NO" << '\n';

	return 0;
}
