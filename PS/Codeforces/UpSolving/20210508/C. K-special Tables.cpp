#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 5e2 + 10;

int a[MAX_N][MAX_N];
vector<int> p;

int main() {
	int N, K; cin >> N >> K;
	for(int i = 1; i <= N * N; i++) p.push_back(i); 

	int idx = 0;
	for(int j = 1; j <= K - 1; j++) 
		for(int i = 1; i <= N; i++) 
			a[i][j] = p[idx++];

	for(int i = 1; i <= N; i++) 
		for(int j = K; j <= N; j++) 
			a[i][j] = p[idx++];

	int sum = 0;
	for(int i = 1; i <= N; i++) sum += a[i][K];
	
	cout << sum << '\n';
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) cout << a[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}
