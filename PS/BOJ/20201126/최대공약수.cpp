#include <iostream>
#include <map>

using namespace std;

const long long int MOD = 1e10;

int main() {
	int N;
	cin>> N;

	map<int,int> A;	
	for(int i = 0; i < N; i++) {
		int x;
		cin >> x;
		
		for(int i = 2; i * i <= x; i++) {
			if(x % i == 0) {
				x /= i;
				A[i]++;
				i = 1;
			}
		}
		
		A[x]++;
	}

	int M;
	cin >> M;
	
	map<int,int> B;
	for(int i = 0; i < M; i++) {
		int x;
		cin >> x;
		
		for(int i = 2; i * i <= x; i++) {
			if(x % i == 0) {
				x /= i;
				B[i]++;
				i = 1;
			}
		}
		
		B[x]++;
	}
	
	long long sum = 1;
	for(auto& p : A) {
		int x = p.first;
		int k = p.second;

		if(B.find(x) != B.end())
			for(int i = 0; i < min(k, B[x]); i++) {
				sum *= x;
				sum %= MOD;
			}
	}
	
	string ans = to_string(sum);
	cout << ans.substr(max(0, (int)ans.size() - 9), 9) << '\n';

	return 0;
}
