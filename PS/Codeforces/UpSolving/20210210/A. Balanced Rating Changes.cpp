#include <iostream>

using namespace std;

int main() {
	int N; cin >> N;

	int a[N], b[N];
	int sum = 0;
	for(int i = 0; i < N; i++) {
		cin >> a[i];
		
		b[i] = (a[i] / 2);
		sum += b[i];
	}

	for(int i = 0; i < N && sum; i++) {
		if(a[i] & 1) {
			if(sum > 0 && a[i] <= 0) b[i]--, sum--;
			else if(sum < 0 && a[i] > 0) b[i]++, sum++;
		}
	}
	
	for(int i = 0; i < N; i++) cout << b[i] << '\n';
	
	return 0;
}
